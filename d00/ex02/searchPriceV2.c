/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 00:40:17 by amittal           #+#    #+#             */
/*   Updated: 2017/08/01 00:40:19 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "string.h"

int searchPrice(struct s_art **arts, int n, char *name)
{
    int i;
    int j;
    int k;

    i = 0;
    j = n - 1;
    while (i <= j)
    {
        k = (i + j) / 2;
        if (strcmp(arts[k]->name, name) == 0)
            return (k);
        else if (strcmp(arts[k]->name, name) < 0)
            i = k + 1;
        else
            j = k - 1;
    }
    return (-1);
}