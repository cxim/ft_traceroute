/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:44:10 by mnarwhal          #+#    #+#             */
/*   Updated: 2019/09/17 13:44:12 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_save(char **s, int fd, char **line)
{
	size_t		i;
	char		*tmp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
	{
		i++;
	}
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strsub(s[fd], i + 1, ft_strlen(s[fd]) - i);
		free(s[fd]);
		s[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[300];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			cat;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((cat = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[cat] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (cat < 0)
		return (-1);
	else if (cat == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_save(s, fd, line));
}
