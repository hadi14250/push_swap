/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_and_tops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:04:00 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/08 14:35:00 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	untill_max_is_last(t_stack **top)
{
	if (get_index(*top, get_max(*top)) < get_size(*top) / 2)
		while (get_index(*top, get_max(*top)) != get_size(*top) - 1)
			rotate_a(top);
	else if (get_index(*top, get_max(*top)) >= get_size(*top) / 2)
		while (get_index(*top, get_max(*top)) != get_size(*top) - 1)
			reverse_rotate_a(top);
}

void	untill_max_is_top(t_stack **top, char c)
{
	if (get_index(*top, get_max(*top)) < get_size(*top) / 2)
	{
		while (get_index(*top, get_max(*top)) != 0)
		{
			if (c == 'a')
				rotate_a(top);
			else if (c == 'b')
				rotate_b(top);
		}
	}
	else if (get_index(*top, get_max(*top)) >= get_size(*top) / 2)
	{
		while (get_index(*top, get_max(*top)) != 0)
		{
			if (c == 'a')
				reverse_rotate_a(top);
			else if (c == 'b')
				reverse_rotate_b(top);
		}
	}
}

void	untill_min_is_top(t_stack **top)
{
	if (get_index(*top, get_min(*top)) < get_size(*top) / 2)
		while (get_index(*top, get_min(*top)) != 0)
			rotate_a(top);
	else if (get_index(*top, get_min(*top)) >= get_size(*top) / 2)
		while (get_index(*top, get_min(*top)) != 0)
			reverse_rotate_a(top);
}

void	full_check(t_stack *top_a, int ac, char **av, int flag)
{
	if (flag == 1)
	{
		neg_check(ac, av);
		check_empty(ac, av);
		check_alphas(ac, av);
	}
	else
		ft_dups(top_a);
}
