/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:35:45 by amittal           #+#    #+#             */
/*   Updated: 2017/07/31 10:35:46 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

int	searchPrice(struct s_art **arts, char *name)
{
	int i;

	i = 0;
	for(i = 0; arts[i] != NULL; i++)
	{
		if (!(strcmp(arts[i]->name, name)))
			return (arts[i]->price);
	i++;
	}
	return (-1);    
}
