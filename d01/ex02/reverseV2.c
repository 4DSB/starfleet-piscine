/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:30:03 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 14:30:03 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct s_stack *stackInit(void)
{
    struct s_stack *stack;

    stack = (struct s_stack *)malloc(sizeof(struct s_stack));
    stack->item = NULL;
    return (stack);

}

void *pop(struct s_stack *stack)
{
    struct s_item *item;
    item = stack->item;
    stack->item = stack->item->next;

    return (item);
}

void push(struct s_stack *stack, char *word)
{
    struct s_item *item;

    item = (struct s_item*)malloc(sizeof(struct s_item ));
    item->word = strdup(word);
    item->next = stack->item;
    stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
    struct s_stack *stack;
    struct s_node *curr;
    
    stack = stackInit();
    curr = lst;
    while (curr)
    {
        push(stack, curr->word);
        curr = curr->next;
    }
    while (stack->item->next)
    {
        printf("%s ", ((struct s_item*)(pop(stack)))->word);
    }
    printf("%s", ((struct s_item*)(pop(stack)))->word);
}

/*
** alternatively if I need to free things then I can just use a s_item type variable
** Lines of code to add:
struct s_item *pop;
while (stack->item->next)
    {
        pop = pop(stack);
        printf("%s ", pop->word);
        free(pop);
    }
    pop = pop(stack);
    printf("%s ", pop->word);
    free(pop);
    stack = NULL;
*/

