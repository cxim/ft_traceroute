/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_floats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:32:04 by mnarwhal          #+#    #+#             */
/*   Updated: 2019/11/07 17:19:24 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				out_non_zero(int **s, char *str, int sight)
{
	int		*new;
	int		len;

	new = *s;
	len = ft_strlen(str);
	if (len >= new[1])
	{
		if (f_f(new[0], 5) > 0 && f_f(new[0], 4) <= 0 && sight != 1)
			len += ft_putchar_mod(' ', new);
		if (f_f(new[0], 4) > 0 && sight != 1)
			len++;
		if (f_f(new[0], 4) > 0 && sight == 0)
			ft_putchar_mod('+', new);
		ft_putstr_mod(str, new[7]);
		free(str);
		return (len);
	}
	else if (new[1] > len)
		return (float_wight_more(&new, len, str, sight));
	return (0);
}

int				for_out_floats(int **s, long double d, char *c, int read)
{
	int		*new;
	int		after_p;

	after_p = 0;
	new = *s;
	d += 0.5;
	c = ft_ftoa(&new, d, after_p, read);
	return (out_zero_float(&new, c, read));
}

static int		out_floats(int **s, long double d, int len)
{
	int		read;
	char	*c;
	int		*new;

	c = NULL;
	read = 0;
	new = *s;
	if (d < 0)
	{
		d = d * -1;
		read = 1;
	}
	if (new[2] == -1)
		new[2] = 6;
	if (new[2] == -3 || new[2] == -2)
		len = for_out_floats(&new, d, c, read);
	else if (new[2] > 0)
	{
		c = ft_ftoa(&new, d, new[2], read);
		len = out_non_zero(&new, c, read);
	}
	return (len);
}

int				work_with_floats(int **s, va_list ap, int read)
{
	long double		d;
	int				*s1;

	s1 = *s;
	if (s1[3] == 3)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	read = out_floats(&s1, d, 0);
	return (read);
}
