/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:48:06 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/08 13:35:56 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_l_sum(unsigned long long sum, int sign, const char *str)
{
	if (sum > 2147483647 && sign == 1)
		return (1);
	else if (sum > 2147483648 && sign == -1)
		return (1);
	else if (*str)
		return (1);
	else
		return (0);
}

void	ft_free_all(t_stack *top, char **splitted, int index)
{
	int	words;

	words = 0;
	while (splitted[words] != NULL)
		words++;
	while (index < words)
	{
		free (splitted[index]);
		index++;
	}
	ft_free(top);
	free(splitted);
	write (2, "Error\n", 6);
	exit (1);
}

int	ft_atol(char *str, t_stack *top, char **splitted, int index)
{
	unsigned long long	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (check_l_sum (sum, sign, str))
		ft_free_all(top, splitted, index);
	return (sum * sign);
}

void	free_av_one(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	exit(0);
}
