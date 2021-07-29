/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_f_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:01:20 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 18:01:22 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			out_zero_float_new_one(int **s, char *str, int sight, int len)
{
	int			*new;

	new = *s;
	if (f_f(new[0], 3) > 0)
	{
		out_zero_float_two(&new, str, sight, len);
		return (new[1]);
	}
	else
	{
		out_zero_float_three(&new, str, sight, len);
		return (new[1]);
	}
}

int			out_zero_float(int **s, char *str, int sight)
{
	int			*new;
	int			len;

	new = *s;
	len = ft_strlen(str);
	if (len >= new[1])
	{
		out_zero_float_one(&new, str, sight);
		return (len);
	}
	else if (new[1] > len)
	{
		if (f_f(new[0], 4) > 0 && sight == 0)
			len++;
		return (out_zero_float_new_one(&new, str, sight, len));
	}
	return (0);
}

void		wight_more_one(int **s, int len, char *str, int sight)
{
	int			*new;

	new = *s;
	if (f_f(new[0], 5) > 0 && f_f(new[0], 4) <= 0 && sight == 0)
		len += ft_putchar_mod(' ', new);
	if (f_f(new[0], 4) > 0 && sight == 0)
		len += ft_putchar_mod('+', new);
	ft_putstr_mod(str, new[7]);
	while (new[1] > len++)
		ft_putchar_mod(' ', new);
	free(str);
}

void		wight_more_two(int **s, int len, char *str, int sight)
{
	int			*new;

	new = *s;
	if (f_f(new[0], 4) > 0 && sight == 0 && f_f(new[0], 2) > 0)
		ft_putchar_mod('+', new);
	if (f_f(new[0], 5) > 0 && f_f(new[0], 4) <= 0 && sight == 0)
		len += ft_putchar_mod(' ', new);
	while (new[1] > len++)
	{
		if (f_f(new[0], 2) > 0)
			ft_putchar_mod('0', new);
		else
			ft_putchar_mod(' ', new);
	}
	if (f_f(new[0], 4) > 0 && sight == 0 && f_f(new[0], 2) <= 0)
		ft_putchar_mod('+', new);
	ft_putstr_mod(str, new[7]);
	free(str);
}

int			float_wight_more(int **s, int len, char *str, int sight)
{
	int			*new;

	new = *s;
	if (f_f(new[0], 3) > 0)
	{
		wight_more_one(&new, len, str, sight);
		return (new[1]);
	}
	else
	{
		if (f_f(new[0], 4) > 0 && sight == 0)
			len++;
		wight_more_two(&new, len, str, sight);
		return (new[1]);
	}
}
