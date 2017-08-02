/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:35:40 by amittal           #+#    #+#             */
/*   Updated: 2017/07/31 17:35:43 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int partition (struct s_art **arts, int p, int r)
{
	struct s_art *temp;
	struct s_art *x = arts[r];
	int i = p - 1;
	int j = 0;
	for (j = p; j <= r; j++)
	{

		if (strcmp(arts[j]->name, x->name) <= 0)
		{
			i = i + 1;
			temp = arts[i];
			arts[i] = arts[j];
			arts[j] = temp;
		}
	}
		if (i < r)
			return i;
		else
			return (i - 1);
}


void  quicksort(struct s_art **arts, int p, int r)
{
	if (p < r)
	{
		int pi = partition(arts, p, r);

		quicksort(arts, p, pi);
		quicksort(arts, pi + 1, r);
	}
}

void  sortArts(struct s_art **arts)
{
	int len;

	len = 0;
	while(arts[len])
		len++;
	quicksort(arts, 0, len - 1);
}