/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_uxo_part_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:54:22 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:54:24 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			true_score_two(int **s, int count)
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

int			true_score(int **s, unsigned long d, int count, int base)
{
	int		*new;
	int		flag;

	new = *s;
	flag = (new[4] == 9 ? 1 : 0);
	if ((f_f(new[0], 1) != 0 && d != 0) || new[4] == 3)
		count = true_score_two(&new, count);
	else if (new[2] == -2 && d == 0 && new[4] != 6)
		return (0);
	else if (new[2] == -3 && new[4] == 8)
		return (0);
	if (new[2] != -3 || new[4] == 6)
		ft_pn_base_p(d, base, flag, new);
	return (count);
}
