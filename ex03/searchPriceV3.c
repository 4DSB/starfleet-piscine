/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 11:33:27 by amittal           #+#    #+#             */
/*   Updated: 2017/08/01 11:33:28 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdlib.h"
#include "limits.h"

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

struct s_item *ht_newpair(char *key, struct s_art *value)
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
	if(((newpair->value = value)) == NULL)
	{
		return NULL;
	}
	newpair->next = NULL;

	return (newpair);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) //add one element in the dictionnary, if FAIL return 0, otherwise 1
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
		next->value->name = strdup(value->name);
		next->value->price = value->price;
	}
	/* Nope, could't find it.  Time to grow a pair. */
	else
	{
		newpair = ht_newpair(key, value);

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


struct s_art *dictSearch(struct s_dict *dict, char *key) //find one element in the dictionnary, if not found, return NULL
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
		return (NULL);

	else
		return pair->value;
}