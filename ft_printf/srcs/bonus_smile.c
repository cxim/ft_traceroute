/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_smile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:44:54 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:45:04 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			get_smile(int i)
{
	int		val;
	char	str[64];

	val = 1;
	val = val + 128511 + i;
	if (val > 12000 && val <= 128555)
	{
		str[0] = ((val >> 18) & 7) | 0xF0;
		str[1] = ((val >> 12) & 0x3F) | 0x80;
		str[2] = ((val >> 6) & 0x3F) | 0x80;
		str[3] = ((val >> 0) & 0x3F) | 0x80;
	}
	write(1, str, 4);
	return (1);
}

int			get_smile_id(const char **p)
{
	int		i;

	i = 0;
	if (find_id(&(*p), "smile_"))
	{
		(*p)--;
		i = ft_atoi(*p);
		(*p)++;
		(*p)++;
	}
	return (i);
}

int			take_smile(const char **p)
{
	int		i;

	(*p)++;
	i = get_smile_id(&(*p));
	if (i > 0 && i < 44)
		return (get_smile(i));
	else
		return (0);
}

int			get_bonus(const char **p)
{
	const char		*k;
	int				i;

	k = *p;
	if (**p == '{')
		i = get_color(&(*p));
	else
		i = take_smile(&(*p));
	if (i == 0)
		*p = k;
	return (0);
}
