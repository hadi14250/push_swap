/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:35:56 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/08 13:36:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>

# define BUFFER_SIZE 6

typedef struct t_stack
{
	int				content;
	int				index;
	struct t_stack	*next;
}					t_stack;

char		*ft_strchr(const char *s, int c);

int			ft_strlen_n(char *str);

char		*ft_strjoin(char *s1, char *s2);

char		*ft_trim_stat(char *str);

char		*ft_trim_line(char *str);

char		*ft_get_line(char *str, int fd);

char		*get_next_line(int fd);

void		check_empty(int ac, char **av);

void		ft_free(t_stack *top);

int			ft_atoi(const char *str);

void		check_sum(unsigned long sum, int sign, const char *str);

void		swap_a(t_stack *top_a);

void		swap_b(t_stack *top_b);

void		swap_ss_a_and_b(t_stack *top_a, t_stack *top_b);

void		push_to_a(t_stack **top_a, t_stack **top_b);

void		push_to_b(t_stack **top_b, t_stack **top_a);

void		reset_index(t_stack *top);

void		rotate_a(t_stack **top_a);

void		add_at_start_list(t_stack **head, int data);

t_stack		*add_end(t_stack *top, int data);

void		rotate_b(t_stack **top_b);

void		rotate_both(t_stack **top_a, t_stack **top_b);

void		reverse_rotate_a(t_stack **top_a);

void		reverse_rotate_b(t_stack **top_b);

void		reverse_rotate_both(t_stack **top_a, t_stack **top_b);

t_stack		*return_tail(t_stack *tail, int i);

void		reset_both_index(t_stack *top_a, t_stack *top_b);

t_stack		*parse_stack(t_stack *top, int ac, char **av);

int			ft_strlens(int ac, char **av, char *sep);

char		*ft_strsjoin(int ac, char **av, char *sep);

int			word_count(char const *s, char c);

char		**ft_split(char const *s, char c);

char		*ft_substr(char const *s, int start, int len);

int			ft_strlen(const char *s);

int			get_max(t_stack *top);

int			get_index(t_stack *top, int max);

int			get_min(t_stack *top);

int			get_size(t_stack *top);

void		*ft_calloc(size_t n, size_t size);

void		ft_bzero(void *s, size_t n);

void		parse_operations(t_stack **top_a, t_stack **top_b);

void		print_stack(t_stack *top, char c);

void		sort_two(t_stack *top_a);

void		sort_three(t_stack **top_a);

void		sort_three_op1(t_stack **top_a);

void		sort_three_op2(t_stack **top_a);

void		sort_four(t_stack **top_a, t_stack **top_b);

void		untill_max_is_last(t_stack **top);

void		untill_max_is_top(t_stack **top, char c);

void		untill_min_is_top(t_stack **top);

void		parse_operations(t_stack **top_a, t_stack **top_b);

void		sort_five(t_stack **top_a, t_stack **top_b);

int			*sort_array(t_stack *top_a);

void		ft_swap(int *a, int *b);

void		slection_sort(int *a, int size);

void		untill_min_is_last(t_stack **top);

int			*get_chunk_indecies(t_stack *top_a);

void		sort_4_chunks(t_stack **top_a, t_stack **top_b);

void		sort_chunks(t_stack **top_a, t_stack **top_b);

int			return_pivot_index(t_stack *top_a);

void		sort_a_chunk(t_stack **top_a, t_stack **top_b);

void		until_num_is_top(t_stack **top_a, int num, char c);

void		pyramid(t_stack **top_b, int pivot_index);

void		sort_chunks(t_stack **top_a, t_stack **top_b);

void		helper(t_stack **top_a, t_stack **top_b, int limit, int *p);

int			*parse_array_and_sort(t_stack *top, int *a);

void		help_for_chunks(t_stack **top_a, t_stack **top_b, int *a, int *p);

void		pyramid_2(t_stack **t_a, t_stack **t_b, int pivot_i, int a_pivot);

void		ft_dups(t_stack *top_a);

void		check_if_sorted(t_stack *top_a);

void		check_alphas(int ac, char **av);

void		full_check(t_stack *top_a, int ac, char **av, int flag);

void		parse_their_stack(t_stack **top_a, t_stack **top_b, t_stack **my_a);

int			ft_strcmp(char *s1, char *s2);

void		parse_their_two(char *s, t_stack **t_a, t_stack **b, t_stack **a);

void		check_if_b_sorted(t_stack *top_a, t_stack *top_b);

void		neg_check(int ac, char **av);

int			check_l_sum(unsigned long long sum, int sign, const char *str);

void		ft_free_all(t_stack *top, char **splitted, int index);

int			ft_atol(char *str, t_stack *top, char **splitted, int index);

void		ft_free_exit(t_stack *t_a, t_stack *t_b, t_stack *my_a, char *s);

void		free_av_one(char **splitted, int words);

#endif
