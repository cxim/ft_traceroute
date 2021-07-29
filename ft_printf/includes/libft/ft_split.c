/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:15:42 by selly             #+#    #+#             */
/*   Updated: 2020/02/19 18:15:45 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				*free_map(char **map, int i)
{
	int		a;

	a = 0;
	if (!map)
		return (NULL);
	if (map)
	{
		while (a < i)
		{
			free(map[a]);
			a++;
		}
		free(map);
		*map = NULL;
	}
	return (NULL);
}

static const char		*next_word(char const *str, char c, int next)
{
	if (next)
		while (*str && *str == c)
			str++;
	else
		while (*str && *str != c)
			str++;
	return (str);
}

static int				count_words(char const *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str = next_word(str, c, 1);
		if (*str)
		{
			str = next_word(str, c, 0);
			i++;
		}
	}
	return (i);
}

char					**ft_split(char const *s, char c)
{
	char			**new;
	const char		*next;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		s = next_word(s, c, 1);
		if (*s)
		{
			next = next_word(s, c, 0);
			new[i] = ft_strsub(s, 0, (next - s));
			if (!new[i])
				return (free_map(new, i));
			i++;
			s = next;
		}
	}
	new[i] = NULL;
	return (new);
}
