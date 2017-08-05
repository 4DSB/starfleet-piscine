/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:41:14 by amittal           #+#    #+#             */
/*   Updated: 2017/08/03 13:41:15 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void insertionSort(struct s_player **players)
{
	int i, j;
	struct s_player *key;
	key = NULL;
	i = 1;
	while (players[i])
	{
		key = players[i];
		j = i - 1;

		while(j >=0 && players[j]->score < key->score)
		{
			players[j + 1] = players [j];
			j = j -  1; 
		}
		players[j+1] = key;
		i++;
	}
	free (key);
}