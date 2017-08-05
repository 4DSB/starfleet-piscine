/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 21:57:11 by amittal           #+#    #+#             */
/*   Updated: 2017/08/02 21:57:12 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


struct s_elem {
	int energy;
	struct s_elem *next;
};

struct s_stack {
	struct s_elem *elem;
	int sum;
};

struct s_tank {
	struct s_stack **stacks;
	int n;
};

struct s_tank *initTank(void)
{
	struct s_tank *tank;

	tank = (struct s_tank *)malloc(sizeof(struct s_tank));
	tank->stacks = NULL;

	tank->stacks[0] = (struct s_stack *)malloc(sizeof(struct s_stack));
	tank->stacks[0] = 
	tank->stacks[1] = (struct s_stack *)malloc(sizeof(struct s_stack));
	return(tank);
}

void s_stack **initstack()
{
	struct s_stack **
}

void tankPush(struct s_tank *tank, int energy);
{
   struct s_stack **stack; 
   struct s_elem *elem;
   //stack = (struct s_stack**)malloc(sizeof(struct s_stack))
   //stack->elem = NULL;
   //stack->sum = 0;

   if(energy)
   {
	   while (1)

			if(stack = NULL)
				stack = initstack();
   }
}

int tankPop(struct s_tank *tank);
