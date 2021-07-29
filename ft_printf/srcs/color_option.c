/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:45:13 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:45:25 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		start(char *str, int flag)
{
	if (flag == 0)
		ft_putstr("\e[");
	ft_putstr(str);
}

int			find_id(const char **p, const char *end)
{
	const char		*test;
	int				i;

	test = *p;
	while ((**p != '}' || **p != ':') && **p && *end)
	{
		if (**p != *end)
		{
			*p = test;
			return (0);
		}
		else
		{
			(*p)++;
			end++;
		}
	}
	i = ((**p) == '}' || (**p) == ':' || ft_isdigit(**p)) ? 1 : 0;
	(*p)++;
	return (i);
}

int			find_decor(const char **p)
{
	int		i;

	if ((i = find_id(&(*p), "invers")) == 1)
		ft_putstr("\e[7;");
	else if ((i = find_id(&(*p), "bold")) == 1)
		ft_putstr("\e[1;");
	else if ((i = find_id(&(*p), "line")) == 1)
		ft_putstr("\e[4;");
	else if ((i = find_id(&(*p), "flash")) == 1)
		ft_putstr("\e[5;");
	else if ((i = find_id(&(*p), "norm")) == 1)
		ft_putstr("\e[0;");
	return (i);
}
