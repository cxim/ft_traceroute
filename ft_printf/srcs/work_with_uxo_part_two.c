/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_uxo_part_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:54:42 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:54:49 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			wight_or_acur(int **s, unsigned long d, int count, int base)
{
	int		*new;
	int		c;
	int		flag;

	new = *s;
	flag = (new[4] == 9 ? 1 : 0);
	c = new[2];
	if ((f_f(new[0], 1) != 0 && d != 0)
		|| (new[2] > count && new[4] == 3))
		wight_or_acur_three(&new, &count, &c);
	while (new[2]-- > count)
		ft_putchar_mod('0', new);
	ft_pn_base_p(d, base, flag, new);
	return (c);
}

int			wight_or_acur_two(int **s, unsigned long d, int count, int base)
{
	int		*new;
	int		flag;

	new = *s;
	flag = (new[4] == 9 ? 1 : 0);
	if (f_f(new[0], 1) != 0 && d != 0)
	{
		if (new[4] == 6)
			count += ft_putchar_mod('0', new);
		else
		{
			if (new[4] == 9)
				count += ft_putstr_mod("0X", new[7]);
			else
				count += ft_putstr_mod("0x", new[7]);
		}
	}
	ft_pn_base_p(d, base, flag, new);
	return (count);
}

int			work_x_o_u(int **s, unsigned long d, int count, int base)
{
	int		*new;

	new = *s;
	if (new[4] == 3)
		new[0] = new[0] * 10 + 1;
	if (new[1] <= count && new[2] <= count)
		return (true_score(&new, d, count, base));
	if ((new[1] > 0 && new[2] <= 0) || (new[2] > 0 && new[1] <= 0))
	{
		if (new[1] > 0 && new[1] > count)
			return (wight_more_count(&new, d, count, base));
		else if (count >= new[1] && count >= new[2])
			return (wight_or_acur_two(&new, d, count, base));
		else if (new[1] == 0 && new[2] > count)
			return (wight_or_acur(&new, d, count, base));
	}
	if (new[1] > count || new[2] > count)
		return (if_flags_more_d(&new, d, count, base));
	return (count);
}
