/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_f_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:51:14 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:51:24 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			c_fp(long double *fp, int *large, unsigned long *ip, int *a_p)
{
	if (*a_p != 0)
	{
		if (*a_p >= 20 && *fp * ft_pow_m(10, 13) > 19 * ft_pow_m(10, 11))
		{
			*fp = *fp * ft_pow_m(10, 19);
			*large = *a_p - 19;
		}
		else
			*fp = (*fp * ft_pow_m(10, *a_p)) + 0.5;
	}
	if (*a_p == 0)
		*fp += 0.5;
	if (int_l(*fp) > int_l(ft_pow_m(10, *a_p - 1)) && *a_p < 20)
	{
		*ip = *ip + 1;
		*fp = *fp - ft_pow_m(10, *a_p);
	}
}

char			*ft_ftoa(int **s, long double n, int after_p, int minus)
{
	unsigned long int		ipart;
	long double				fpart;
	int						large;
	int						*new;
	char					*res;

	new = *s;
	large = 0;
	ipart = (unsigned long int)n;
	fpart = n - (long double)ipart;
	c_fp(&fpart, &large, &ipart, &after_p);
	res = (char*)malloc(sizeof(char) * 1000);
	ipart = i_to_s_i(&new, ipart, res, minus);
	if (after_p == 0)
		return (res);
	res[ipart] = '.';
	i_to_s(fpart, res + ipart + 1, after_p, large);
	return (res);
}

void			out_zero_float_one(int **s, char *str, int sight)
{
	int					*new;

	new = *s;
	if (f_f(new[0], 4) > 0 && sight == 0)
		ft_putchar_mod('+', new);
	ft_putstr_mod(str, new[7]);
	if (f_f(new[0], 1) > 0)
		ft_putchar_mod('.', new);
	free(str);
}

void			out_zero_float_two(int **s, char *str, int sight, int len)
{
	int					*new;

	new = *s;
	if (f_f(new[0], 5) > 0 && f_f(new[0], 4) <= 0 && sight == 0)
		len += ft_putchar_mod(' ', new);
	if (f_f(new[0], 4) > 0 && sight == 0)
		ft_putchar_mod('+', new);
	ft_putstr_mod(str, new[7]);
	if (f_f(new[0], 1) > 0)
		len += ft_putchar_mod('.', new);
	while (new[1] > len++)
		ft_putchar_mod(' ', new);
	free(str);
}

void			out_zero_float_three(int **s, char *str, int sight, int len)
{
	int					*new;

	new = *s;
	if (f_f(new[0], 4) > 0 && sight == 0 && f_f(new[0], 2) > 0)
		ft_putchar_mod('+', new);
	if (f_f(new[0], 5) > 0 && f_f(new[0], 4) <= 0 && sight == 0)
		len += ft_putchar_mod(' ', new);
	while (new[1] > len++)
	{
		if (f_f(new[0], 2) > 0 && sight == 0)
			ft_putchar_mod('0', new);
		else
			ft_putchar_mod(' ', new);
	}
	if (f_f(new[0], 4) > 0 && sight == 0 && f_f(new[0], 2) <= 0)
		ft_putchar_mod('+', new);
	ft_putstr_mod(str, new[7]);
	if (f_f(new[0], 1) > 0)
		ft_putchar_mod('.', new);
	free(str);
}
