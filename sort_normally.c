/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_normally.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:22:47 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/06 00:14:00 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slection_sort(int *a, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	i = 1;
	while (i < size)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
		i++;
	}
}

int	*sort_array(t_stack *top_a)
{
	int		size;
	t_stack	*tmp;
	int		*array;
	int		i;

	i = 0;
	array = NULL;
	tmp = NULL;
	tmp = top_a;
	size = get_size(tmp);
	array = malloc (size * sizeof (int));
	tmp = top_a;
	while (i < size && tmp != NULL)
	{
		array[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (array);
}
