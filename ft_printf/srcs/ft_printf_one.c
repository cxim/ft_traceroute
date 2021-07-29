/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:46:33 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:46:44 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			format_args(int **s, va_list ap)
{
	int			*new;
	int			format;
	int			print;

	new = *s;
	format = new[4];
	print = 0;
	if (format == 1 || format == 2)
		print = work_with_chars(&(*s), ap, 0, "(null)");
	else if (format == 3)
		print = work_with_pointer(&(*s), ap, 0);
	else if (format == 4 || format == 5)
		print = work_with_int(&(*s), ap, 0, NULL);
	else if (format == 6)
		print = work_with_o(&(*s), ap, 0);
	else if (format == 7)
		print = work_with_u(&(*s), ap, 0);
	else if (format == 8)
		print = work_with_x(&(*s), ap, 0);
	else if (format == 9)
		print = work_with_x_big(&(*s), ap, 0);
	else if (format == 10)
		print = work_with_floats(&(*s), ap, 0);
	ft_numzero(&(*s), 5);
	return (print);
}

int			empty_args(int **s, const char **p, va_list ap, int end)
{
	int			read;
	int			*buf_conv;
	char		*flag;

	read = 0;
	buf_conv = *s;
	if (**p == '%')
	{
		flag = "%";
		read = work_with_int(&(*s), ap, 0, flag);
		(*p)++;
		ft_numzero(&(*s), 5);
	}
	if (end <= 0 && buf_conv[1] > 0 && f_f(buf_conv[0], 3))
	{
		ft_numzero(&(*s), 5);
		print_last_spaces(&(*s), 2, 1);
		read += buf_conv[1] - 1;
	}
	else
		ft_numzero(&(*s), 5);
	return (read);
}

int			read_conv(va_list ap, const char **p, int **s, int end)
{
	int			count_read;
	int			*buf_conv;
	int			conv_id;

	buf_conv = *s;
	if ((conv_id = check_flag(&(*p), 0)) > 0)
		buf_conv[0] = conv_id;
	if ((conv_id = check_wight(&(*p))) > 0)
		buf_conv[1] = conv_id;
	if ((conv_id = check_accuracy(&(*p))) != -1)
		buf_conv[2] = conv_id;
	if ((conv_id = check_type(&(*p))) > 0)
		buf_conv[3] = conv_id;
	if ((end = check_conv(&(*p))) > 0)
		buf_conv[4] = end;
	if (end > 0)
		count_read = format_args(&(*s), ap);
	else
		count_read = empty_args(&(*s), &(*p), ap, end);
	return (count_read);
}

void		print_percent(int *read, int spaces, int i, int fd)
{
	*read += ft_print_symbol(i / 2, '%', fd);
	if (spaces > 0)
		*read += ft_print_symbol(spaces, ' ', fd);
	*read = -(*read);
}

void		find_doubles(const char **p, int *i, int *spaces)
{
	int		stack;

	stack = 1;
	(*i)++;
	while ((**p == '%' || **p == ' '))
	{
		(*p)++;
		*i += **p == '%' ? 1 : 0;
		if (**p == '%' && stack == 1)
		{
			stack = 0;
			*spaces = 0;
		}
		else if (**p == '%' && stack == 0)
			break ;
		else if (**p == ' ')
			(*spaces)++;
	}
}
