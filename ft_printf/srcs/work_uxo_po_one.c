/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_uxo_po_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:48:35 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:48:48 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	if_minus_in_fl_one(int **s, int z)
{
	int			*new;

	new = *s;
	if (new[4] == 9)
		ft_putstr_mod("0X", new[7]);
	else
		ft_putstr_mod("0x", new[7]);
	return (z + 2);
}

static int	if_minus_in_fl_two(int z, int *n)
{
	ft_putchar_mod('0', n);
	return (z + 1);
}

int			if_minus_in_flag_on(int **s, unsigned long d, int count, int base)
{
	int			*n;
	int			z;
	int			flag;

	n = *s;
	flag = (n[4] == 9 ? 1 : 0);
	z = n[2] > count ? n[2] : count;
	if (f_f(n[0], 1) != 0 && d != 0 && n[4] != 6)
		z = if_minus_in_fl_one(&n, z);
	else if (f_f(n[0], 1) != 0 && d != 0 && n[4] == 6)
		z = if_minus_in_fl_two(z, n);
	if (n[4] == 6 && n[2] > count && f_f(n[0], 1) != 0 && n[1] > n[2]
		&& f_f(n[0], 3) != 0 && d != 0)
	{
		count = count + 1;
		z = z - 1;
	}
	while (n[2]-- > count)
		ft_putchar_mod('0', n);
	ft_pn_base_p(d, base, flag, n);
	while (n[1]-- > z)
		ft_putchar_mod(' ', n);
	return (n[1]);
}

static int	if_minus_off_part_three(int **s, int back_int)
{
	int			*new;

	new = *s;
	if (new[4] == 6 && new[2] != -3)
	{
		if (new[2] == -2 && f_f(new[0], 1) <= 0)
		{
			ft_putchar_mod(' ', new);
			return (back_int);
		}
		ft_putchar_mod('0', new);
		return (back_int);
	}
	else
		ft_putchar_mod(' ', new);
	return (back_int);
}

int			if_minus_in_flag_off(int **s, unsigned long d, int count, int base)
{
	int			*n;
	int			back_int;
	int			flag;

	n = *s;
	flag = (n[4] == 9 ? 1 : 0);
	back_int = n[1];
	if (f_f(n[0], 2) != 0 && f_f(n[0], 1) != 0)
		if_minus_off_part_one(&n, d, count);
	else if (f_f(n[0], 2) != 0 && f_f(n[0], 1) <= 0)
		while (n[1]-- > count)
			ft_putchar_mod('0', n);
	else
	{
		if_minus_off_part_two(&n, d, count);
		if (d == 0 && n[2] == -2)
			return (if_minus_off_part_three(&n, back_int));
	}
	if ((f_f(n[0], 1) != 0 && d != 0 && f_f(n[0], 2) == 0) || n[4] == 3)
		write_o_x_o(&n);
	((n[2] == -3 && f_f(n[0], 1) <= 0) || (n[2] == -3 && (n[4] == 8 ||
		n[4] == 9))) ? ft_putchar_mod(' ', n) : ft_pn_base_p(d, base, flag, n);
	return (back_int);
}
