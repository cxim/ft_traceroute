/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:11:00 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/08/22 17:12:33 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_line(char **p_n, char **line, char **remainder)
{
	char			*temp;

	*p_n = *p_n ? *p_n : ft_strchr(*remainder, '\0');
	if (**p_n == '\n')
	{
		**p_n = '\0';
		*line = ft_strdup(*remainder);
		temp = *remainder;
		if ((*p_n)[1] != '\0')
			*remainder = ft_strdup(*p_n + 1);
		else
			*remainder = NULL;
		free(temp);
	}
	else
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	return (1);
}

int		some_funk(int readed, char *remainder, char **line)
{
	if (readed < 0 && (!remainder || remainder[0] == 0))
		return (-1);
	else if (readed == 0 && (!remainder || remainder[0] == 0))
	{
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

int		get_next_line2(int fd, char **line)
{
	static char		*remainder = NULL;
	char			*temp;
	char			buf[BUFFER_SIZE + 1];
	int				readed;
	char			*p_n;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	p_n = remainder ? ft_strchr(remainder, '\n') : NULL;
	while (!p_n && (readed = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readed] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(remainder, buf);
		free(temp);
		if ((p_n = ft_strchr(remainder, '\n')))
			break ;
	}
	if (some_funk(readed, remainder, line) < 1)
		return (some_funk(readed, remainder, line));
	else
		return (get_line(&p_n, line, &remainder));
}
