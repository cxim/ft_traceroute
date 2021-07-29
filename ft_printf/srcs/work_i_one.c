/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_i_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:47:36 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:47:50 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long	rem_sign_l(long double num, int *flag)
{
	unsigned long		new;

	*flag = num >= 0 ? 0 : 1;
	new = num < 0 ? -num : num;
	return (new);
}

long			rem_sign(long num, int *flag)
{
	*flag = num >= 0 ? 0 : 1;
	num = num < 0 ? -num : num;
	return (num);
}

char			*read_num(int *s, va_list ap, int *f)
{
	char				*str;
	long long			test;

	str = NULL;
	if (s[3] == 1)
	{
		test = rem_sign((signed short)va_arg(ap, signed int), &(*f));
		str = ft_itoa(test);
	}
	else if (s[3] == 2)
		str = ft_itoa_long(rem_sign_l(va_arg(ap, long), &(*f)));
	else if (s[3] == 22)
	{
		test = rem_sign_l(va_arg(ap, long long), &(*f));
		str = ft_itoa_long(test);
	}
	else if (s[3] == 11)
	{
		test = (signed char)va_arg(ap, signed int);
		str = ft_itoa(rem_sign(test, &(*f)));
	}
	else if (s[3] == 0)
		str = ft_itoa_long(rem_sign(va_arg(ap, int), &(*f)));
	return (str);
}

int				print_prefix_1(int times, char prefix, int *n)
{
	int					read;

	read = 0;
	while (times > 0)
	{
		read += ft_putchar_mod(prefix, n);
		times--;
	}
	return (read);
}

int				a_print(int *new, int d, char *str, int count)
{
	int					spaces;
	int					nool;

	spaces = new[1] - new[2] - 1;
	if (!f_f(new[0], 3))
		print_prefix_1(spaces, ' ', new);
	if (d)
		ft_putchar_mod('-', new);
	else
		ft_putchar_mod('+', new);
	nool = new[2] - count;
	print_prefix_1(nool, '0', new);
	ft_putstr_mod(str, new[7]);
	if (f_f(new[0], 3))
		print_prefix_1(spaces, ' ', new);
	ft_strdel(&str);
	return (new[1]);
}
