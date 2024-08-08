/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:39:35 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/06 06:20:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	reverse_rotate_b(t_stack **top_b)
{
	t_stack	*tail;
	t_stack	*top;

	if (!(*top_b) || !(*top_b)->next)
		return ;
	top = *top_b;
	top = return_tail(top, 1);
	tail = *top_b;
	tail = return_tail(tail, 0);
	tail->next = NULL;
	top->next = *top_b;
	*top_b = top;
	write (1, "rrb\n", 4);
	reset_index (*top_b);
}

t_stack	*return_tail(t_stack *tail, int i)
{
	t_stack	*tmp;

	tmp = NULL;
	tmp = tail;
	if (i == 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		return (tmp);
	}
	else
		while (tmp->next->next != NULL)
			tmp = tmp->next;
	return (tmp);
}

void	reset_both_index(t_stack *top_a, t_stack *top_b)
{
	reset_index (top_a);
	reset_index (top_b);
}

// if function rturn_tail flag is 1 that means return the last 
//element of the list and else return the second last element;
void	reverse_rotate_both(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tail;
	t_stack	*top;

	tail = NULL;
	top = NULL;
	if (!(*top_a) || !(*top_b) || !(*top_a)->next || !(*top_b)->next)
		return ;
	top = *top_b;
	top = return_tail (top, 1);
	tail = *top_b;
	tail = return_tail(tail, 0);
	tail->next = NULL;
	top->next = *top_b;
	*top_b = top;
	top = *top_a;
	top = return_tail (top, 1);
	tail = *top_a;
	tail = return_tail(tail, 0);
	tail->next = NULL;
	top->next = *top_a;
	*top_a = top;
	write (1, "rrr\n", 4);
	reset_both_index (*top_a, *top_b);
}
