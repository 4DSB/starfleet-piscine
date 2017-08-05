/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:16:01 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 13:16:02 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void printReverse(struct s_node *lst)
{
    if (lst->next)
    {
        printReverse(lst->next);
        printf(" %s", lst->word);
    }
    else
        printf("%s", lst->word);
}