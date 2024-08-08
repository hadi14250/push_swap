/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:49:54 by hakaddou          #+#    #+#             */
/*   Updated: 2024/08/08 18:08:34 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *top)
{
	t_stack	*tmp;

	tmp = NULL;
	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}

void	reset_index(t_stack *top)
{
	int	i;

	if (!top)
		return ;
	i = 0;
	while (top != NULL)
	{
		top->index = i;
		i++;
		top = top->next;
	}
}

void	add_at_start_list(t_stack **head, int data)
{
	t_stack	*tmp;

	tmp = ft_calloc (sizeof (t_stack *), 2);
	tmp->content = data;
	tmp->next = NULL;
	tmp->next = *head;
	(*head) = tmp;
}

t_stack	*add_end(t_stack *top, int data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		index_a;

	tmp = ft_calloc (sizeof (t_stack *), 2);
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->content = data;
	if (!top)
	{
		tmp->index = 0;
		return (tmp);
	}
	tmp2 = top;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	index_a = tmp2->index;
	tmp->index = (index_a + 1);
	tmp2->next = tmp;
	return (top);
}

t_stack	*parse_stack(t_stack *top, int ac, char **av)
{
	int		i;
	char	*tmp_str;
	char	**tmp_2d;
	int		words;

	words = 0;
	tmp_str = ft_strsjoin (ac, av, " ");
	tmp_2d = ft_split (tmp_str, ' ');
	free(tmp_str);
	while (tmp_2d[words] != NULL)
		words++;
	if (words <= 1)
		free_av_one(tmp_2d, words);
	i = 0;
	while (i < words)
	{
		ft_atol(tmp_2d[i], top, tmp_2d, i);
		top = add_end (top, ft_atoi (tmp_2d[i], top));
		free(tmp_2d[i]);
		i++;
	}
	free (tmp_2d);
	return (top);
}
