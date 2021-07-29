/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_uxo_pt_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:49:19 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:49:21 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			wight_more_count_one(int **s, int count)
{
	int		*new;

	new = *s;
	if (new[4] == 6)
		count += ft_putchar_mod('0', new);
	else
	{
		if (new[4] == 9)
			count += ft_putstr_mod("0X", new[7]);
		else
			count += ft_putstr_mod("0x", new[7]);
	}
	return (count);
}

int			wight_more_count_three(int **s)
{
	int		*new;

	new = *s;
	if (f_f(new[0], 1) != 0 && new[4] == 6)
	{
		ft_putchar_mod('0', new);
		new[1] = new[1] - 1;
	}
	write_new_one(new[1], new);
	return (new[2]);
}

void		wight_more_last(int **s, unsigned long d, int *count, int base)
{
	int		*new;
	int		flag;

	new = *s;
	flag = (new[4] == 9 ? 1 : 0);
	if (f_f(new[0], 1) != 0 && d != 0)
		*count = wight_more_count_one(&new, *count);
	if ((new[2] == -3 && f_f(new[0], 1) == 0)
		|| (new[2] == -3 && (new[4] == 8 || new[4] == 9)))
		ft_putchar_mod(' ', new);
	else if (new[4] == 3 && d == 0)
	{
		ft_putstr_mod("0x", new[7]);
		ft_pn_base_p(d, base, flag, new);
		new[1] = new[1] - 2;
	}
	else
		ft_pn_base_p(d, base, flag, new);
	while (new[1]-- > *count)
		ft_putchar_mod(' ', new);
}

int			wight_more_count(int **s, unsigned long d, int count, int base)
{
	int		*new;
	int		int_back;

	new = *s;
	int_back = new[1];
	if (f_f(new[0], 3) == 0)
		return (if_minus_in_flag_off(&new, d, count, base));
	else if (f_f(new[0], 3) != 0)
	{
		if (d == 0 && new[2] == -2)
			return (wight_more_count_three(&new));
		wight_more_last(&new, d, &count, base);
		return (int_back >= count ? int_back : count);
	}
	return (int_back);
}

void		wight_or_acur_three(int **s, int *count, int *c)
{
	int		*new;

	new = *s;
	*c = *c + 2;
	if (new[4] == 6)
	{
		ft_putchar_mod('0', new);
		*count = *count + 1;
		*c = *c - 2;
	}
	else
	{
		if (new[4] == 9)
			ft_putstr_mod("0X", new[7]);
		else
			ft_putstr_mod("0x", new[7]);
	}
}
