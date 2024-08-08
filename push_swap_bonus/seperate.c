/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:34:12 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/06 11:05:12 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strlens(int ac, char **av, char *sep)
{
	int	i;
	int	j;
	int	b;

	b = 0;
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		b += j;
		i++;
	}
	b += (ft_strlen (sep) * ac) - ft_strlen (sep);
	return (b);
}

char	*ft_strsjoin(int ac, char **av, char *sep)
{
	int		i;
	int		b;
	int		j;
	int		d;
	char	*tmp;

	i = 0;
	tmp = ft_calloc ((ft_strlens (ac, av, sep)) + 1, 1);
	b = 0;
	while (++i < ac)
	{
		j = 0;
		d = 0;
		while (av[i][j] != '\0')
			tmp[b++] = av[i][j++];
		while (sep[d] != '\0')
			tmp[b++] = sep[d++];
	}
	tmp[b] = '\0';
	return (tmp);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;
	int	done;

	i = 0;
	cnt = 0;
	done = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && !done)
			done = 1;
		else if (s[i] != c && done)
		{
			++cnt;
			done = 0;
		}
		++i;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			words;
	char		**tmp;

	if (!s)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	tmp = ft_calloc(sizeof(char *) * (words + 1), 1);
	if (!tmp)
		return (NULL);
	words = 0;
	while (s[i] && words < word_count(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tmp[words++] = ft_substr(s + i, 0, j);
		i += j;
	}
	tmp[words] = 0;
	return (tmp);
}
