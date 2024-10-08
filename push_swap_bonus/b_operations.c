/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 05:20:13 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/08 12:45:10 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_b(t_stack *top_b)
{
	int	tmp;

	if (top_b == NULL || top_b->next == NULL)
		return ;
	tmp = top_b->content;
	top_b->content = top_b->next->content;
	top_b->next->content = tmp;
}

void	push_to_b(t_stack **top_b, t_stack **top_a)
{
	int		tmp;
	t_stack	*tmp_stack;

	tmp_stack = NULL;
	if (!(*top_a))
		return ;
	tmp = (*top_a)->content;
	tmp_stack = (*top_a)->next;
	free (*top_a);
	*top_a = tmp_stack;
	add_at_start_list (top_b, tmp);
	reset_index(*top_b);
	reset_index(*top_a);
}

void	rotate_b(t_stack **top_b)
{
	t_stack	*tail;
	t_stack	*new_top;

	if (!(*top_b) || !(*top_b)->next)
		return ;
	tail = NULL;
	new_top = NULL;
	new_top = (*top_b)->next;
	tail = *top_b;
	tail = return_tail (tail, 1);
	tail->next = *top_b;
	(*top_b)->next = NULL;
	*top_b = new_top;
	reset_index (*top_b);
}

void	rotate_both(t_stack **top_a, t_stack **top_b)
{
	t_stack	*new_top;
	t_stack	*tail;

	if (!(*top_a) || !(*top_b) || !(*top_a)->next || !(*top_b)->next)
		return ;
	new_top = (*top_a)->next;
	tail = *top_a;
	tail = return_tail (tail, 1);
	tail->next = *top_a;
	(*top_a)->next = NULL;
	*top_a = new_top;
	new_top = (*top_b)->next;
	tail = *top_b;
	tail = return_tail(tail, 1);
	tail->next = *top_b;
	(*top_b)->next = NULL;
	*top_b = new_top;
	reset_both_index (*top_a, *top_b);
}
