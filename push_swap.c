/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 05:24:01 by hakaddou          #+#    #+#             */
/*   Updated: 2022/06/20 17:16:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_check(t_stack *top_a, int ac, char **av, int flag)
{
	if (flag == 1)
	{
		neg_check(ac, av);
		check_empty(ac, av);
		check_alphas(ac, av);
	}
	else
	{
		ft_dups(top_a);
		check_if_sorted(top_a);
	}
}

int	main(int ac, char **av)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_b = NULL;
	top_a = NULL;
	full_check(top_a, ac, av, 1);
	top_a = parse_stack (top_a, ac, av);
	full_check(top_a, ac, av, 2);
	parse_operations (&top_a, &top_b);
	ft_free (top_a);
}

/*
make re && rm *.o && ./push_swap {100..1}

make re && rm *.o && valgrind --leak-check=full ./push_swap 

python visualizer:

make re && rm *.o && /usr/bin/python3 python_visualizer.py
 `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

*/
