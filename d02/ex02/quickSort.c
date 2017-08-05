/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:25:31 by amittal           #+#    #+#             */
/*   Updated: 2017/08/03 16:25:31 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int partition (struct s_player **players, int p, int r)
{
	struct s_player *temp;
	struct s_player *x = players[r];
	int i = p - 1;
	int j = 0;
	for (j = p; j <= r; j++)
	{

		if (players[j]->score >= x->score)
		{
			i = i + 1;
			temp = players[i];
			players[i] = players[j];
			players[j] = temp;
		}
	}
		if (i < r)
			return i;
		else
			return (i - 1);
}

void  quicksort_helper(struct s_player **players, int p, int r)
{
	if (p < r)
	{
		int pi = partition(players, p, r);

		quicksort_helper(players, p, pi);
		quicksort_helper(players, pi + 1, r);
	}
}

void quickSort(struct s_player **players)
{
   	int len;

	len = 0;
	while(players[len])
		len++;
	quicksort_helper(players, 0, len - 1);
    
}