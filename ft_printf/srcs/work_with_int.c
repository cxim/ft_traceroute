/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:20:42 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:53:25 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_and_format_one(int **s, int d)
{
	int		*new;
	int		read;

	new = *s;
	read = 0;
	if (f_f(new[0], 4) && !d)
		read += ft_putchar_mod('+', new);
	else if (f_f(new[0], 5) && !d)
		read += ft_putchar_mod(' ', new);
	if (d)
		read += ft_putchar_mod('-', new);
	return (read);
}

int			print_and_format_two(int **s)
{
	int		*new;
	int		read;

	new = *s;
	read = 0;
	if (new[1] > 0 && !(f_f(new[0], 4)))
		read += ft_putchar_mod(' ', new);
	else if (new[1] > 0 && f_f(new[0], 4) && f_f(new[0], 3))
		read += ft_putchar_mod(' ', new);
	return (read);
}

int			print_and_format(int **s, int read, char *str, int d)
{
	int		*new;
	int		w;
	int		len;

	new = *s;
	w = 0;
	len = ft_strlen_mod(str) + d;
	(!d && f_f(new[0], 4)) ? len++ : len;
	if ((new[1] > len) || (new[2] > len))
		read += general_wigt_ac(&(*s), d, &w, str);
	else
		read += print_and_format_one(&new, d);
	if (*str == '0' && (new[2] == -2 || new[2] == -3))
		read += print_and_format_two(&new);
	else
		read += ft_putstr_mod(str, new[7]);
	if (f_f(new[0], 3))
	{
		if (f_f(new[0], 4) != 1 && !(d) && new[2] > 0 &&
			f_f(new[0], 2) > 0 && f_f(new[0], 5)
			> 0 && new[2] > len)
			w = w + 1;
		read += print_prefix_1(w, ' ', new);
	}
	return (read);
}

int			work_with_int(int **s, va_list ap, int read, char *flag)
{
	int		*new;
	int		d;
	char	*str;
	int		len;

	new = *s;
	if (!flag)
	{
		if (!(str = read_num(*s, ap, &d)))
			return (print_warning(1));
	}
	else
	{
		str = flag;
		d = 0;
	}
	len = ft_strlen_mod(str) + d;
	if ((f_f(new[0], 4) > 0 || d == 1) &&
		new[1] > new[2] && ((new[2] == len) || (new[2] == len + 1)))
		return (a_print(new, d, str, ft_strlen(str)));
	read = print_and_format(&(*s), read, str, d);
	if (!flag)
		ft_strdel(&str);
	return (read);
}
