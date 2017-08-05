/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 22:29:34 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 22:29:35 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>


void sortStones(struct s_stone **stone)
{
	int swap;
	int is_swap;

	struct s_stone *p1;
	struct s_stone *tmp;
	struct s_stone *p2 = NULL;

	if (stone == NULL)
		return;
	is_swap = 1;
	
	while(is_swap)
	{	
		is_swap = 0;
		swap = 0;
		p1 = *stone;
		while(p1->next != p2 && p1->next != tmp)
		{
			if(p1->size > p1->next->size)
			{
				swap = p1->size;
				p1->size = p1->next->size;
				p1->next->size = swap;
				is_swap = 1;
				tmp = p1->next;	
			}
			p1 = p1->next;
		}
		p2 = p1;
	}
}