/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_extras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 00:49:15 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/07 12:50:48 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	return_pivot_index(t_stack *top_a)
{
	if (get_size(top_a) < 30)
		return (1);
	else if (get_size(top_a) >= 30 && get_size(top_a) < 80)
		return (2);
	else if (get_size(top_a) >= 80 && get_size(top_a) < 150)
		return (8);
	else if (get_size(top_a) >= 150 && get_size(top_a) < 400)
		return (10);
	else if (get_size(top_a) >= 400 && get_size(top_a) < 1000)
		return (16);
	else if (get_size(top_a) >= 1000 && get_size(top_a) < 2500)
		return (25);
	else
		return (50);
}

int	*get_chunk_indecies(t_stack *top_a)
{
	int	*pivots;
	int	pivot;
	int	i;

	pivots = malloc ((return_pivot_index(top_a)) * sizeof(int));
	i = 0;
	pivot = get_size(top_a) / return_pivot_index(top_a);
	while (i < return_pivot_index(top_a) - 1)
	{
		pivots[i] = pivot * (i + 1);
		i++;
	}
	return (pivots);
}

int	*parse_array_and_sort(t_stack *top, int *a)
{
	a = NULL;
	a = sort_array(top);
	slection_sort (a, get_size(top));
	return (a);
}

void	sort_a_chunk(t_stack **top_a, t_stack **top_b)
{
	while (get_size(*top_b) != 0)
	{
		untill_max_is_top(top_b, 'b');
		push_to_a(top_a, top_b);
	}
}

void	pyramid_2(t_stack **t_a, t_stack **t_b, int pivot_i, int a_pivot)
{
	int		i;
	int		*a;
	t_stack	*tmp;

	tmp = NULL;
	a = ft_calloc(pivot_i, sizeof(int));
	i = 0;
	tmp = *t_b;
	while (i < pivot_i && tmp != NULL)
	{
		a[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	slection_sort(a, pivot_i);
	pivot_i = a[(pivot_i / 2) - 1];
	if (*t_b && (*t_b)->next && (*t_b)->content < pivot_i
		&& (*t_a)->content > a_pivot)
		rotate_both(t_a, t_b);
	else if (*t_b && (*t_b)->next && (*t_b)->content < pivot_i)
		rotate_b (t_b);
	free (a);
}
