/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 19:14:17 by amittal           #+#    #+#             */
/*   Updated: 2017/08/01 19:14:18 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


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



struct s_dict *dictInit(int capacity) //initialize the dictionnary, given as parameter the capacity of the array.
{
	struct s_dict *dict = NULL;
	int i;

	if(capacity < 1)
		return (NULL);
	if((dict = malloc(sizeof(struct s_dict))) == NULL)
		return (NULL);
	if ((dict->items=malloc(sizeof(struct s_item*) * capacity)) == NULL)
		return (NULL);
	for (i = 0; i <= capacity; i++)
	{
		dict->items[i] = NULL;
	
	}
	dict->capacity = capacity;
	return (dict);
}
struct s_item *ht_newpair(char *key, int value)
{
	 struct s_item *newpair;

	if((newpair = malloc(sizeof(struct s_item))) == NULL)
	{
		return NULL;
	}
	if ((newpair->key = strdup(key)) == NULL)
	{
		return NULL;
	}
	if(((newpair->value = value)) == 0)
	{
		return NULL;
	}
	newpair->next = NULL;

	return (newpair);
}



int	dictInsert(struct s_dict *dict, char *key, int value) //add one item in the dictionnary, if FAIL return 0, otherwise 1
{
	size_t hasheval = 0;
	size_t bin = 0;
	struct s_item *newpair = NULL;
	struct s_item *next = NULL;
	struct s_item *last = NULL;

	hasheval = hash(key);
	bin = hasheval % dict->capacity;
	next = dict->items[bin];

	while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0 )
	{
		last = next;
		next = next->next;
	}
	/* There's already a pair.  Let's replace that string. */
	if (next != NULL && next->key !=NULL && strcmp(key, next->key) == 0)
	{
		//free(next->value);
		next->key = key;
		next->value = value;
	}
	else
	{
		newpair = ht_newpair(key, value);
		if (!newpair)
			return (0);

		/* We're at the start of the linked list in this bin. */
		if(next == dict->items[bin])
		{
			newpair->next = next;
			dict->items[bin] = newpair;
		}

		/* We're at the end of the linked list in this bin. */
		else if(next == NULL)
		{
			last->next = newpair;
		}

		/* We're in the middle of the list. */
		else
		{
			newpair->next = next;
			last->next = newpair;
		}
	}
	return (1);


}

int	dictSearch(struct s_dict *dict, char *key) //find one element in the dictionnary, if not found, return -1
{
	size_t bin = 0;
	struct s_item *pair;
	size_t hasheval = 0;
	

	hasheval = hash(key);

	bin = hasheval % dict->capacity;
	
	/* Step through the bin, looking for our value. */
	pair = dict->items[bin];
	while (pair != NULL && pair->key != NULL && strcmp (key, pair->key) > 0)
		pair = pair->next;
	
	/* Did we actually find anything? */
	if (pair == NULL || pair ->key == NULL || strcmp(key, pair->key) != 0)
		return (-1);

	else
		return pair->value;
}
// OTHER

int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char *compress(char *book, struct s_dict *dict)
{
	char *p1;
	char *p2;
	int i;
	//char *cbook;
	char copy[2048];
	int check;
	char *head;
	
	
	i = 0;
	p1 = book;
	p2 = book;
	head = p1;
	printf("!!!!");
	while (!ft_isalpha(*p1) && !ft_isalpha(*p2))
			{
				p1++;
				p2++;
				printf("!!!!");
			}
	while (p1)
	{
		int i = 0;

		while(ft_isalpha(p2[i]))
		{
			copy[i] = p2[i];
			i++;
		}
		copy[i] = '\0';
		check = dictSearch(dict, copy);
		if (check != 0)
		{
			*p1 = '@';
			p1++;
			*p1 = (char)check;
			
		}
		else 
		{
			p1 += i;
		}
		*(p1++) = *(p2++);
	}
	*p1 = '\0';
	return (head);
}