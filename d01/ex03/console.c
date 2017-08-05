/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:03:10 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 16:03:11 by amittal          ###   ########.fr       */
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

int pop(struct s_stack *stack)
{
	struct s_item *item;
	item = stack->item;
	stack->item = stack->item->next;

	return (item->idx);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item;

	item = (struct s_item*)malloc(sizeof(struct s_item ));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char *console(void)
{
	struct s_stack *stack;
	char *str;
	char input[255];


	str = (char*)malloc(sizeof(char) * 255);
	str[0] = '\0';

	stack = stackInit();
	
	while (1)
	{
		printf("?: ");
		scanf("%[^\n]%*c", input);
		if(strcmp(input, "SEND") == 0)
		{
			return(str);
		}
		if(strcmp(input, "UNDO") == 0)
		{
			str[pop(stack)] = 0;
			printf("%s\n\n", str);
		}
		else
		{
			
			push(stack, strlen(str));
			if(str[0])
			{
				strcat(str, " ");
			}
			strcat(str, input);
			printf("%s\n\n", str);
		}
	}
}