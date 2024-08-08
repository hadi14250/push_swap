/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:57:26 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/08 12:56:42 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*their_top_a;
	t_stack	*their_top_b;
	t_stack	*my_top_a;
	t_stack	*my_top_b;

	their_top_a = NULL;
	their_top_b = NULL;
	my_top_a = NULL;
	my_top_b = NULL;
	full_check(my_top_a, ac, av, 1);
	my_top_a = parse_stack (my_top_a, ac, av);
	full_check(my_top_a, ac, av, 2);
	parse_operations (&my_top_a, &my_top_b);
	their_top_a = parse_stack(their_top_a, ac, av);
	parse_their_stack(&their_top_a, &their_top_b, &my_top_a);
	ft_free (my_top_a);
	ft_free(their_top_a);
	ft_free(their_top_b);
}

/*
make re && rm *.o && ./push_swap 3 2 1 5 | ./checker 3 2 1 5

*/

void	parse_their_stack(t_stack **top_a, t_stack **top_b, t_stack **my_top_a)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!ft_strcmp(s, "sa\n"))
			swap_a(*top_a);
		else if (!ft_strcmp(s, "rra\n"))
			reverse_rotate_a(top_a);
		else if (!ft_strcmp(s, "pb\n"))
			push_to_b(top_b, top_a);
		else if (!ft_strcmp(s, "pa\n"))
			push_to_a(top_a, top_b);
		else if (!ft_strcmp(s, "rb\n"))
			rotate_b(top_b);
		else
			parse_their_two(s, top_a, top_b, my_top_a);
		free(s);
	}
	check_if_b_sorted(*top_a, *top_b);
}

void	ft_free_exit(t_stack *top_a, t_stack *top_b, t_stack *my_top_a, char *s)
{
	write (2, "Error\n", 6);
	ft_free(top_a);
	ft_free(top_b);
	ft_free(my_top_a);
	free(s);
	exit(1);
}

void	parse_their_two(char *s, t_stack **t_a, t_stack **t_b, t_stack **my_a)
{
	if (!ft_strcmp(s, "rrb\n"))
		reverse_rotate_b(t_b);
	else if (!ft_strcmp(s, "rr\n"))
		rotate_both(t_a, t_b);
	else if (!ft_strcmp(s, "rrr\n"))
		reverse_rotate_both(t_a, t_b);
	else if (!ft_strcmp(s, "sb\n"))
		swap_b(*t_b);
	else if (!ft_strcmp(s, "ss\n"))
		swap_ss_a_and_b(*t_a, *t_b);
	else if (!ft_strcmp(s, "ra\n"))
		rotate_a(t_a);
	else
		ft_free_exit(*t_a, *t_b, *my_a, s);
}

void	check_if_b_sorted(t_stack *top_a, t_stack *top_b)
{
	int		i;
	t_stack	*tmp;

	tmp = NULL;
	i = 0;
	tmp = top_a;
	while (top_a && tmp->next != NULL && tmp->content < tmp->next->content)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == get_size(top_a) - 1 && top_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/*
make re && rm *.o && ./push_swap {100..1}

make re && rm *.o && valgrind --leak-check=full ./push_swap 

python visualizer:

make re && rm *.o && /usr/bin/python3 python_visualizer.py
 `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

*/
