/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_some_wight_aruc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:46:53 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:47:21 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		write_new_one(int i, int *n)
{
	while (i-- > 0)
		ft_putchar_mod(' ', n);
}

void		if_minus_off_part_two(int **s, unsigned long d, int count)
{
	int *new;

	new = *s;
	if (f_f(new[0], 1) != 0 && d != 0)
		count = count + 2;
	if (new[4] == 3 && d == 0)
		count = count + 2;
	while (new[1]-- > count)
		ft_putchar_mod(' ', new);
}

void		if_minus_off_part_one(int **s, unsigned long d, int count)
{
	int		*new;

	new = *s;
	if (d == 0)
		while (new[1]-- > count)
			ft_putchar_mod('0', new);
	else
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
		while (new[1]-- > count)
			ft_putchar_mod('0', new);
	}
}

void		write_o_x_o(int **s)
{
	int		*new;

	new = *s;
	if (new[4] == 6)
		ft_putstr_mod(" 0", new[7]);
	else
	{
		if (new[4] == 9)
			ft_putstr_mod("0X", new[7]);
		else
			ft_putstr_mod("0x", new[7]);
	}
}
