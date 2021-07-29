/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_uxo_po_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:48:54 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:49:09 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		if_wight_more_acur_out_one(int **s, int count)
{
	int		*new;

	new = *s;
	if (new[4] == 6 && new[2] < count)
		ft_putchar_mod('0', new);
	else if (new[4] == 6)
		ft_putchar_mod(' ', new);
	else if (new[4] != 6)
	{
		if (new[4] == 9)
			ft_putstr_mod("0X", new[7]);
		else
			ft_putstr_mod("0x", new[7]);
	}
}

void		if_wight_more_acur_two(int **s, unsigned long d, int z, int count)
{
	int		*new;

	new = *s;
	if (f_f(new[0], 1) > 0 && d != 0 && new[4] == 6)
		z = z + 1;
	else if (f_f(new[0], 1) > 0 && d != 0 && new[4] != 6)
		z = z + 2;
	while (new[1]-- > z)
		ft_putchar_mod(' ', new);
	if (f_f(new[0], 1) > 0 && d != 0)
		if_wight_more_acur_out_one(&new, count);
	while (new[2]-- > count)
		ft_putchar_mod('0', new);
}

int			if_wight_more_acur(int **s, unsigned long d, int count, int base)
{
	int		z;
	int		*new;
	int		back_int;
	int		flag;

	new = *s;
	flag = (new[4] == 9 ? 1 : 0);
	z = new[2] > count ? new[2] : count;
	back_int = new[1];
	if (f_f(new[0], 3) == 0)
	{
		if_wight_more_acur_two(&new, d, z, count);
		ft_pn_base_p(d, base, flag, new);
		return (back_int);
	}
	else if (f_f(new[0], 3) != 0)
		if_minus_in_flag_on(&new, d, count, base);
	return (back_int);
}

int			if_flags_more_d_two(int **s, unsigned long d, int base, int count)
{
	int		*new;
	int		back_int;
	int		flag;

	new = *s;
	back_int = new[2];
	flag = (new[4] == 9 ? 1 : 0);
	if (f_f(new[0], 1) != 0 && d != 0 && new[4] != 6)
	{
		if (new[4] == 3)
			back_int = back_int + 2;
		(new[4] == 9) ? ft_putstr_mod("0X", new[7]) :
		ft_putstr_mod("0x", new[7]);
	}
	while (new[2]-- > count)
		ft_putchar_mod('0', new);
	ft_pn_base_p(d, base, flag, new);
	return (back_int);
}

int			if_flags_more_d(int **s, unsigned long d, int count, int base)
{
	int		*new;
	int		back_int;
	int		flag;

	new = *s;
	flag = (new[4] == 9 ? 1 : 0);
	back_int = new[2];
	if (new[2] > new[1])
		return (if_flags_more_d_two(&new, d, base, count));
	else if (new[1] >= new[2])
		return (if_wight_more_acur(&new, d, count, base));
	else if (new[2] > count)
	{
		while (new[2]-- > count)
			ft_putchar_mod('0', new);
		ft_pn_base_p(d, base, flag, new);
		return (back_int);
	}
	return (count);
}
