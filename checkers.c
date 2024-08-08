/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:47:12 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/07 14:16:58 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dups(t_stack *top_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = top_a;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->content == tmp2->content)
			{
				write(2, "Error\n", 6);
				ft_free(top_a);
				exit (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	check_if_sorted(t_stack *top_a)
{
	int		i;
	t_stack	*tmp;

	tmp = NULL;
	i = 0;
	tmp = top_a;
	while (tmp->next != NULL && tmp->content < tmp->next->content)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == get_size(top_a) - 1)
	{
		ft_free(top_a);
		exit (0);
	}
}

void	check_alphas(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' && (av[i][j] != ' ' && av[i][j] != '-'
			&& av[i][j] != '+'))
			|| (av[i][j] > '9' && (av[i][j] != ' ' && av[i][j] != '-'
			&& av[i][j] != '+')))
			{
				write(2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	check_sum(unsigned long sum, int sign, const char *str, t_stack *t)
{
	if (sum > 2147483647 && sign == 1)
	{
		write(2, "Error\n", 6);
		ft_free(t);
		exit (1);
	}
	else if (sum > 2147483648 && sign == -1)
	{
		write(2, "Error\n", 6);
		ft_free(t);
		exit (1);
	}
	else if (*str)
	{
		write (2, "Error\n", 6);
		ft_free(t);
		exit (1);
	}
}

void	neg_check(int ac, char **av)
{
	int	i;
	int	d;

	i = 1;
	while (i < ac)
	{
		d = 0;
		while (av[i][d] != '\0')
		{
			if ((av[i][d] == '-' && (av[i][d + 1] < '0' || av[i][d + 1] > '9'))
			|| (av[i][d] == '+' && (av[i][d + 1] < '0' || av[i][d + 1] > '9')))
			{
				write(1, "Error\n", 6);
				exit (i);
			}
			d++;
		}
		i++;
	}
}
