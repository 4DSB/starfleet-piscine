/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:13:24 by amittal           #+#    #+#             */
/*   Updated: 2017/08/04 11:13:25 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void    get_more_info(struct s_info *info, struct s_node *root)
{
	if(root == NULL)
		return;
	if(root->value < info->min)
		info->min = root->value; 
	if(root->value > info->min)
		info->max = root->value;;
	info->elements++;
	get_more_info(info, root->left);
	get_more_info(info, root->right);
}

int		isBST(struct s_node *root)
{
	static struct s_node *prev = NULL;
	if (root)
	{
		if (!isBST(root->left))
			return (0);
		if (prev != NULL && root->value <= prev->value)
			return (0);
		prev = root;
		return isBST(root->right);
	}
	return (1);
}

int max(int a, int b)
{
  return (a >= b)? a: b;
} 

int height(struct s_node *root)
{
   if(root == NULL)
       return 0;
    return (1 + max(height(root->left), height(root->right)));
} 

int		isBalanced(struct s_node *root)
{
	int lh;
	int rh;

	if(root == NULL)
		return (1); 
	lh = height(root->left);
	rh = height(root->right);
 
	if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return (1);
   return 0;
}


struct s_info   getInfo(struct s_node *root)
{
	struct s_info info;
	memset(&info, 0, sizeof(struct s_info));
	if(root == NULL)
		return (info);
	memset(&info, 0, sizeof(struct s_info));
	info.min = root->value;
	info.max = root->value;
	info.elements = 0;
	get_more_info(&info, root);
	info.height = height(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);

	return(info);
}