/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_format_char_str.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:17:07 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 18:13:51 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_putstr_mod_l(char *str, int len, int fd)
{
	int			i;

	i = 0;
	while (*str && len)
	{
		if (fd < 0)
			ft_putchar(*str);
		else
			ft_putchar_fd(*str, fd);
		str++;
		i++;
		len--;
	}
	return (i);
}

int				pr_str(char *s, int *n, int l)
{
	int			print;
	char		prefix;
	int			width;

	print = 0;
	prefix = ' ';
	if (ft_strlen_mod(s) > n[2] && n[2] > 0 && n[1] > n[2])
		width = n[1] - n[2];
	else if (l != 0)
		width = n[1] - ft_strlen_mod(s);
	else
		width = n[1];
	while (width-- > 0)
		print += ft_putchar_mod(prefix, n);
	print += ft_putstr_mod_l(s, l, n[7]);
	return (print);
}

int				pr_chars(char c, int *n)
{
	int			print;
	char		prefix;
	int			width;

	width = n[1];
	print = 0;
	prefix = ' ';
	width--;
	while (width > 0)
	{
		if (n[7] < 0)
			ft_putchar(prefix);
		else
			ft_putchar_fd(prefix, n[7]);
		print++;
		width--;
	}
	if (n[7] < 0)
		ft_putchar(c);
	else
		ft_putchar_fd(c, n[7]);
	print++;
	return (print);
}

int				wight_length(int **s, int *len, char *str)
{
	int			*new;
	int			read;

	new = *s;
	read = 0;
	if (new[2] != -3 && new[2] != -2 && new[2] != 0)
		*len = new[4] == 2 ? ft_strlen_mod(str) : 1;
	else
		*len = 0;
	if ((new[4] == 2) && *len < new[1])
	{
		if (new[2] < *len && new[2] > 0)
			*len = *len - new[2];
		read = new[1] - *len;
	}
	if ((new[4] == 1) && new[1] > 1)
		read = new[1] - 1;
	*len = new[4] == 2 ? ft_strlen_mod(str) : 1;
	if (new[4] == 2 && ft_strlen_mod(str) > new[2] && new[2] > 0)
		*len = new[2];
	if (new[2] == -3 || new[2] == -2 || new[2] == 0)
		*len = 0;
	return (read);
}

int				work_with_chars(int **s, va_list ap, int read, char *empty)
{
	int			c;
	char		*str;
	int			len;
	int			*new;

	new = *s;
	str = NULL;
	c = 0;
	if (all_flags(*s) == -1)
		return (-1);
	if (new[4] == 1)
		c = va_arg(ap, int);
	else if (!(str = va_arg(ap, char *)))
		str = empty;
	read = wight_length(&(*s), &len, str);
	if ((new[1] + new[5]) >= 1 && !(f_f(new[0], 3)))
		return (new[4] == 2 ? pr_str(str, new, len) : pr_chars(c, new));
	print_last_spaces(&new, 2, len);
	read = (new[4] == 2 ? ft_putstr_mod_l(str, len, new[7])
			+ read : ft_putchar_mod(c, new) + read);
	return (read);
}
