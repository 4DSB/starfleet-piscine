/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:35:57 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 19:36:00 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return(queue);
}

char *dequeue(struct s_queue *queue)
{
	struct s_node *tmp;
	char *ch;

	if(isEmpty(queue))
		return NULL;
	tmp = queue->first;
	if(queue->first->next || queue->first)
		queue->first = queue->first->next;
	ch = (char *)malloc(sizeof(char) * strlen(tmp->message));
	ch = strdup(tmp->message);
	free(tmp);
	return(ch);
}

void enqueue(struct s_queue *queue, char *message)
{
	
	struct s_node *last;
	struct s_node *tmp;

	last = (struct s_node*)malloc(sizeof(struct s_node));
	last->message = message;
	last->next = NULL;
	
	if(!isEmpty(queue))
		{
			queue->last->next = last;
			queue->last = last;
			tmp = queue->last;		
		}
	else
	{
		queue->first = last;
		queue->last = last;
	}
	
}

char *peek(struct s_queue *queue)
{
	if(isEmpty(queue))
		return NULL;
	else
		return(queue->first->message);
	
}

int isEmpty(struct s_queue *queue)
{
	return(queue->last == NULL || queue->first == NULL);
}