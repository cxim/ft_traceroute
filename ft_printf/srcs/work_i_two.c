/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_i_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:47:58 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:48:16 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			wight_and_accur(int **s, int d, int *w, int len)
{
	int		*new;
	int		buf;
	int		read;

	new = *s;
	buf = *w;
	read = 0;
	if (f_f(new[0], 2) && new[2] + 1 > len && f_f(new[0], 5))
		new[2] = new[2] + 1;
	if (f_f(new[0], 2) && f_f(new[0], 5) && d)
		new[1] = new[1] + 1;
	buf = new[1] - new[2];
	if (d || f_f(new[0], 4))
		buf--;
	if (d == 0 && new[1] > len && new[2] > len && f_f(new[0], 2) > 0 &&
		f_f(new[0], 4) > 0 && f_f(new[0], 5) > 0)
		buf++;
	if (f_f(new[0], 3) != 1)
		read += print_prefix_1(buf, ' ', new);
	*w = buf;
	return (read);
}

int			check_general_one(int **s, int d, int *w, int len)
{
	int		*new;
	int		read;

	read = 0;
	new = *s;
	if ((new[1] > len) && (new[2] > len) && (new[1] > new[2]))
		read += wight_and_accur(&(*s), d, &(*w), len);
	else if ((new[1] > len) && (new[1] > new[2]) && !(f_f(new[0], 2)))
	{
		*w = new[1] - len;
		if (f_f(new[0], 3) != 1)
			read += print_prefix_1(new[1] - len, ' ', new);
	}
	else if (f_f(new[0], 2) && new[2] > 0 && new[1] >
		len && new[1] > new[2])
	{
		*w = new[1] - len;
		if (f_f(new[0], 3) != 1)
			read += print_prefix_1(new[1] - len, ' ', new);
	}
	return (read);
}

int			check_general_two(int **s, int d, int *w, int len)
{
	int		*new;
	int		read;

	new = *s;
	read = 0;
	if (new[2] > len)
	{
		if (d || f_f(new[0], 4))
		{
			if (!(f_f(new[0], 2) && f_f(new[0], 5)))
				len--;
		}
		if (f_f(new[0], 2) && new[1] < new[2] && f_f(new[0], 5))
			len--;
		read += print_prefix_1(new[2] - len, '0', new);
	}
	else if (new[1] > len && new[2] == -1 && f_f(new[0], 2))
	{
		if (f_f(new[0], 3))
			*w += new[1] - len;
		else
			read += print_prefix_1(new[1] - len, '0', new);
	}
	return (read);
}

int			check_general_three(int **s, int d, int *len, int *w)
{
	int		*new;
	int		read;

	read = 0;
	new = *s;
	if ((!d && (new[2] > new[1]) && f_f(new[0], 2)) ||
		(f_f(new[0], 3) || (new[2] > new[1])) ||
		(f_f(new[0], 2) && new[2] <= 0) ||
		(f_f(new[0], 2) && new[1] > new[2] && new[2] > *len))
		read += ft_putchar_mod(' ', new);
	(*w)--;
	if (f_f(new[0], 2))
		*len = *len + 1;
	return (read);
}

int			general_wigt_ac(int **s, int d, int *w, char *str)
{
	int		read;
	int		*new;
	int		len;

	read = 0;
	new = *s;
	len = ft_strlen_mod(str) + d;
	(!d && f_f(new[0], 4)) ? len++ : len;
	read += check_general_one(&new, d, w, len);
	if (d)
		read += ft_putchar_mod('-', new);
	else if (f_f(new[0], 4))
	{
		if (*str == '0' && (new[2] == -2 || new[2] == -3) && new[1] > 0 &&
			!(f_f(new[0], 3)))
			read += ft_putchar_mod(' ', new);
		read += ft_putchar_mod('+', new);
	}
	else if (f_f(new[0], 5))
		read += check_general_three(&new, d, &len, w);
	read += check_general_two(&new, d, w, len);
	return (read);
}
