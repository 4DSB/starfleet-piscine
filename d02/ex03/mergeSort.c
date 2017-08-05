/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:12:01 by amittal           #+#    #+#             */
/*   Updated: 2017/08/03 18:12:02 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/*
struct s_player {
  char  *timeStamp;
  int   score;
  char  *name;
};
*/

void merge(struct s_player **players, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp playersays */
    struct s_player *L[n1], *R[n2];
 
    /* Copy data to temp playersays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = players[l + i];
    for (j = 0; j < n2; j++)
        R[j] = players[m + 1+ j];
 
    /* Merge the temp playersays back into players[l..r]*/
    i = 0; // Initial index of first subplayersay
    j = 0; // Initial index of second subplayersay
    k = l; // Initial index of merged subplayersay
    while (i < n1 && j < n2)
    {
        if (L[i]->score <= R[j]->score)
        {
            players[k] = L[i];
            i++;
        }
        else
        {
            players[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        players[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        players[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_helper(struct s_player **players, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort_helper(players, l, m);
        mergeSort_helper(players, m+1, r);
 
        merge(players, l, m, r);
    }
}

struct s_player **mergeSort(struct s_player **players)
{
    int i;

    i = 0;
    while (players[i])
        i++;
    mergeSort_helper(players, 0, i - 1);
    return(players);
}
