/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_n_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:43:06 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:43:48 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_baza_f(int i, int flag)
{
	if (flag == 0)
	{
		if (i >= 0 && i <= 9)
			return (i + '0');
		if (i >= 10 && i <= 36)
			return (i + 'a' - 10);
	}
	else if (flag == 1)
	{
		if (i >= 0 && i <= 9)
			return (i + '0');
		if (i >= 10 && i <= 36)
			return (i + 'A' - 10);
	}
	return (i);
}

void			ft_pn_base_p(unsigned long long nbr, int base, int flag, int *s)
{
	if (nbr >= (unsigned long long)base)
	{
		ft_pn_base_p(nbr / base, base, flag, s);
		ft_putchar_mod(ft_baza_f(nbr % base, flag), s);
	}
	else
	{
		ft_putchar_mod(ft_baza_f(nbr % base, flag), s);
	}
}

int				ft_putnbr_base_c(unsigned long long nbr, int base)
{
	static int		count;

	count = 0;
	if (nbr >= (unsigned long long)base)
	{
		ft_putnbr_base_c(nbr / base, base);
		count++;
	}
	else
	{
		count++;
	}
	return (count);
}
