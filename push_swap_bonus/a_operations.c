/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 05:16:11 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/08 12:42:26 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_stack *top_a)
{
	int	tmp;

	if (top_a == NULL || top_a->next == NULL)
		return ;
	tmp = top_a->content;
	top_a->content = top_a->next->content;
	top_a->next->content = tmp;
}

void	swap_ss_a_and_b(t_stack *top_a, t_stack *top_b)
{
	t_stack	*tmp;

	if (!top_a || !top_a->next || !top_b || !top_b->next)
		return ;
	tmp = NULL;
	tmp = ft_calloc (sizeof (t_stack *), 1);
	tmp->content = top_a->content;
	top_a->content = top_a->next->content;
	top_a->next->content = tmp->content;
	tmp->content = top_b->content;
	top_b->content = top_b->next->content;
	top_b->next->content = tmp->content;
	free (tmp);
}

void	push_to_a(t_stack **top_a, t_stack **top_b)
{
	int		tmp;
	t_stack	*tmp_stack;

	tmp_stack = NULL;
	if (!(*top_b))
		return ;
	tmp = (*top_b)->content;
	tmp_stack = (*top_b)->next;
	free (*top_b);
	*top_b = tmp_stack;
	add_at_start_list (top_a, tmp);
	reset_index(*top_b);
	reset_index(*top_a);
}

void	rotate_a(t_stack **top_a)
{
	t_stack	*tail;
	t_stack	*new_top;

	if (!(*top_a) || !(*top_a)->next)
		return ;
	tail = NULL;
	new_top = NULL;
	new_top = (*top_a)->next;
	tail = *top_a;
	tail = return_tail (tail, 1);
	tail->next = *top_a;
	(*top_a)->next = NULL;
	*top_a = new_top;
	reset_index (*top_a);
}

void	reverse_rotate_a(t_stack **top_a)
{
	t_stack	*tail;
	t_stack	*top;

	if (!(*top_a) || !(*top_a)->next)
		return ;
	top = *top_a;
	top = return_tail(top, 1);
	tail = *top_a;
	tail = return_tail(tail, 0);
	tail->next = NULL;
	top->next = *top_a;
	*top_a = top;
	reset_index (*top_a);
}
