/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:43:50 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/06 13:13:58 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_max(t_stack *top)
{
	int	max;

	if (!top)
	{
		write (2, "ERROR in get_max function\n", 26);
		exit (1);
	}
	max = INT_MIN;
	while (top != NULL)
	{
		if (max < top->content)
			max = top->content;
		top = top->next;
	}
	return (max);
}

int	get_index(t_stack *top, int max)
{
	int	index;

	if (!top)
	{
		write (2, "ERROR in get_max_index function\n", 30);
		exit (1);
	}
	while (top != NULL)
	{
		if (max == top->content)
			index = top->index;
		top = top->next;
	}
	return (index);
}

int	get_min(t_stack *top)
	{
	int	min;

	if (!top)
	{
		write (2, "ERROR in get_min function\n", 26);
		exit (1);
	}
	min = INT_MAX;
	while (top != NULL)
	{
		if (min > top->content)
			min = top->content;
		top = top->next;
	}
	return (min);
}

int	get_size(t_stack *top)
{
	int		i;
	t_stack	*tmp;

	if (!top)
		return (0);
	tmp = NULL;
	tmp = top;
	i = 0;
	if (!tmp)
	{
		write (2, "ERROR in get_size function\n", 26);
		exit (1);
	}
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
