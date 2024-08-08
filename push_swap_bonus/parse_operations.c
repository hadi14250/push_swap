/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:25:49 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/07 11:19:06 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_five(t_stack **top_a, t_stack **top_b)
{
	untill_min_is_top(top_a);
	push_to_b(top_b, top_a);
	sort_four(top_a, top_b);
	push_to_a(top_a, top_b);
}

void	parse_operations(t_stack **top_a, t_stack **top_b)
{
	int	size;

	size = get_size(*top_a);
	if (size == 2)
		sort_two (*top_a);
	else if (size == 3)
		sort_three (top_a);
	else if (size == 4)
		sort_four(top_a, top_b);
	else if (size == 5)
		sort_five (top_a, top_b);
	else
		sort_chunks(top_a, top_b);
}
