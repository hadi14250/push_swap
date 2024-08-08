/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:27:32 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/07 11:12:54 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pyramid(t_stack **top_b, int pivot_index)
{
	int		i;
	int		*a;
	t_stack	*tmp;

	tmp = NULL;
	a = ft_calloc (pivot_index, sizeof(int) * 2);
	i = 0;
	tmp = *top_b;
	while (i < pivot_index && tmp != NULL)
	{
		a[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	slection_sort(a, pivot_index);
	pivot_index = a[(pivot_index / 2)];
	if (*top_b && (*top_b)->next && (*top_b)->content < pivot_index)
		rotate_b (top_b);
	free (a);
}

void	sort_chunks(t_stack **top_a, t_stack **top_b)
{
	int	*pivots;
	int	*a;
	int	limit;

	limit = return_pivot_index(*top_a);
	a = NULL;
	a = parse_array_and_sort(*top_a, a);
	pivots = get_chunk_indecies(*top_a);
	help_for_chunks(top_a, top_b, a, pivots);
	helper(top_a, top_b, limit, pivots);
}

void	helper(t_stack **top_a, t_stack **top_b, int limit, int *p)
{
	int	*a;

	a = NULL;
	a = parse_array_and_sort(*top_a, a);
	free (p);
	free (a);
	while (get_size (*top_a) != 0)
	{
		push_to_b(top_b, top_a);
		pyramid(top_b, limit);
	}
	sort_a_chunk(top_a, top_b);
}

void	help_for_chunks(t_stack **top_a, t_stack **top_b, int *a, int *p)
{
	int	i;
	int	d;
	int	limit;

	limit = return_pivot_index(*top_a);
	i = 0;
	d = 0;
	while (i < limit - 1)
	{
		while (d < p[i] - 6)
		{
			if ((*top_a)->content <= a[p[i] + 9])
			{
				push_to_b(top_b, top_a);
				d++;
			}
			else
				rotate_a(top_a);
			pyramid_2(top_a, top_b, limit, a[p[i] + 9]);
		}
		i++;
	}
	free (a);
}
