/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations_v2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 07:01:53 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/06 11:04:39 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_two(t_stack *top_a)
{
	t_stack	*tmp;

	tmp = NULL;
	tmp = top_a;
	if (tmp->next->content < tmp->content)
		swap_a(tmp);
}

void	sort_three_op1(t_stack **top_a)
{
	rotate_a(top_a);
	swap_a(*top_a);
}

void	sort_three_op2(t_stack **top_a)
{
	reverse_rotate_a(top_a);
	swap_a(*top_a);
}

void	sort_three(t_stack **top_a)
{
	int	min_index;
	int	max_index;

	max_index = get_index(*top_a, get_max(*top_a));
	min_index = get_index(*top_a, get_min(*top_a));
	if (max_index == 0 && min_index == 2)
		sort_three_op1(top_a);
	else if (max_index == 2 && min_index == 1)
		swap_a(*top_a);
	else if (max_index == 1 && min_index == 0)
		sort_three_op2(top_a);
	else if (max_index == 1 && min_index == 2)
		reverse_rotate_a(top_a);
	else if (max_index == 0 && min_index == 1)
		rotate_a(top_a);
}

void	sort_four(t_stack **top_a, t_stack **top_b)
{
	untill_min_is_top(top_a);
	push_to_b(top_b, top_a);
	sort_three(top_a);
	push_to_a(top_a, top_b);
}
