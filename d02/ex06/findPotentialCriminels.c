/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 20:55:31 by amittal           #+#    #+#             */
/*   Updated: 2017/08/03 20:55:32 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int getMax(struct s_criminal **criminals, int n)
{
    int mx = criminals[0]->description;
    for (int i = 1; i < n; i++)
        if (criminals[i]->description > mx)
            mx = criminals[i]->description;
    return mx;
}
 
// A function to do counting sort of criminals[] according to
// the digit represented by exp.
void countSort(struct s_criminal **criminals, int n, int exp)
{
	struct s_criminal **output; // output criminalsay
	output = malloc(sizeof(struct s_criminal) * n);
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[((criminals[i]->description)/exp)%10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output criminalsay
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (criminals[i]->description/exp)%10 ] - 1] = criminals[i];
        count[ (criminals[i]->description/exp)%10 ]--;
    }
 
    // Copy the output criminalsay to criminals[], so that criminals[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        criminals[i] = output[i];
}
 

void sortCriminals(struct s_criminal **criminals)
{
		int n;

		n = 0;
		while(criminals[n])
			n++;
		int m = getMax(criminals, n);
		for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(criminals, n, exp);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int n;
	int i;
	int des;
	int start;
	int stop;
	
	des = 0;
	i = 0;
	n = 0;
	start = 0;
	
	while(criminals[n])
			n++;

	des += info->gender * 1000000;
	des += info->height * 100000;
	des += info->hairColor * 10000;
	des += info->eyeColor * 1000;
	des += info->glasses * 100;
	des += info->tattoo * 10;
	des += info->piercing * 1;

	start = binarySearch(criminals, 0, n-1, des);
	stop = start;
	while(criminals[stop]->description == des && stop < n-1)
		stop++;
	if(stop != n-1)
		criminals[stop] = 0;
	
	return(&criminals[start]);
}


int binarySearch(struct s_criminal **criminals, int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
    // Check if x is present at mid
    if (criminals[m]->description == x && criminals[m-1]->description != x) 
        return m;  
		
    // If x greater, ignore left half  
    if (criminals[m]->description < x) 
        l = m + 1; 
 
    // If x is smaller, ignore right half 
    else
         r = m - 1; 
  }
 
  // if we reach here, then element was not present
  return -1; 
}
