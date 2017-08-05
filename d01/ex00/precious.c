/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:17:11 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 10:17:11 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
** making a new dlinklist.
*/

struct s_node *ft_dlstnew (char c)
{
	struct s_node *newNode;

	newNode = (struct s_node*)malloc(sizeof(struct s_node));
	newNode->c = c;
	newNode->next = newNode;
	newNode->prev = newNode;
	return newNode;
}

/*
** adding a new node to the head or tail based on value of ht(0 for rail, 1 for head)
*/

void        ft_dlstadd(struct s_node **alst, struct s_node *new, int ht)
{
	struct s_node 	*prev;
	struct s_node	*curr;

	if(alst == NULL)
	{
		*alst = new;
		return;
	}
	curr = *alst;
	prev = curr->prev;
	
	prev->next = new;
	new->prev = prev;
	new->next = curr;
	curr->prev = new;
	if(ht == 1)
		*alst = new;
}


char *precious(int *text, int size)
{
	(void) size;
	(void)text;
	struct s_node **list;
	struct s_node *curr;
	struct s_node *new;
	char *ret;
	int j;
	int tmp;

	ret = (char *)malloc(sizeof(char) * size  + 1);
	list = NULL;
	int len = strlen(CS);
	curr = ft_dlstnew(CS[0]);
	for (int i = 1; i < len; i++)
	{
		
		new = ft_dlstnew(CS[i]);
		ft_dlstadd(&curr, new, 0);
	}
	for (j = 0; j < size; j++)
	{
		tmp = text[j];
		if(tmp < 0)
		{
			while (tmp != 0)
			{
				curr = curr->prev;
				tmp++;
			}
		}
		else
		{
			while (tmp!=0)
			{
				curr = curr->next;
				tmp--;
			}
		}
		ret[j] = curr->c;
		
	}
	ret[j] = '\0';
	return(ret);
}