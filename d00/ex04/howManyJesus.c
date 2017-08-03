/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:14:14 by amittal           #+#    #+#             */
/*   Updated: 2017/08/01 15:14:15 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"
#include <stdlib.h>

size_t hash(char *input) //return hash result
{

	size_t length = strlen(input);
    size_t hash = 0;
    for(size_t i = 0; i < length; i++) {
        char c = input[i];
        int a = c - '0';
        hash = (hash * 10) + a;     
    } 

    return hash;

}

int howManyJesus(char *bible, char *jesus)
{
	int hash_jesus;
	int hash_bible;
	int len_jesus;
	int len_bible;
	int i;
	char *cpy;
	int count;

	i = 0;
	count = 0;
	len_jesus = strlen(jesus);
	cpy = (char *)malloc(sizeof(char) *len_jesus + 1);
	bzero(cpy, len_jesus);
	hash_jesus = hash(jesus);
	len_bible = strlen(bible);

	for (int i = 0; i < len_bible - len_jesus + 1; i++)
	{
		strncpy(cpy, &bible[i], len_jesus);
		hash_bible = hash(cpy);
		if(hash_bible == hash_jesus)
			if(strcmp(jesus, cpy) == 0)
				count++;
	}
	return(count);
}