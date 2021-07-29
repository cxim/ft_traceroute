/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:00:10 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:46:24 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			percent_double(const char **line, int spaces, int i, int *conv)
{
	int				read;
	const char		*p;

	read = 0;
	p = *line;
	if (*p == '%' && (*(p + 1)))
		find_doubles(&p, &i, &spaces);
	if (i / 2 > 0)
	{
		print_percent(&read, spaces, i, conv[7]);
		*line = p;
	}
	else
		(*line)++;
	return (read);
}

int			print_format(va_list ap, const char **p, int **conv, int *symbols)
{
	int				test;

	if ((test = read_conv(ap, &(*p), &(*conv), 0)) == -1)
		*symbols = 0;
	else
		*symbols += test;
	if (test == -1)
		return (test);
	return (*symbols);
}

void		bonus_or_print(const char **p, int *symbols, int *conv)
{
	if ((**p == '{' || **p == ':') && conv[7] < 0)
		get_bonus(&(*p));
	if (**p != '%')
		*symbols += ft_putchar_mod(*((*p)++), conv);
}

int			format_str(const char *format, va_list ap, int **conv, int symbols)
{
	const char		*p;
	int				test;

	p = format;
	while (*p)
	{
		if (*p != '%')
			bonus_or_print(&p, &symbols, *conv);
		else
		{
			if (*p != '%')
				symbols += ft_putchar_mod(*(p++), *conv);
			else
			{
				if ((test = percent_double(&p, 0, 0, *conv)) < 0)
					symbols += (-test);
				else if (print_format(ap, &p, &(*conv), &symbols) == -1)
					return (symbols);
			}
		}
		print_last_spaces(&(*conv), 1, 0);
	}
	return (symbols);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	int				*conv;
	int				read_symbols;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	conv = ft_new_integer_list(8);
	conv[7] = -1;
	read_symbols = format_str(format, ap, &conv, 0);
	va_end(ap);
	free(conv);
	conv = NULL;
	return (read_symbols);
}
