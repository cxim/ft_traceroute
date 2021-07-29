/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_f_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:50:21 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:50:41 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				int_l(unsigned long int n)
{
	int		size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

static void		reverse(char *str, int len)
{
	int				i;
	int				j;
	int				temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int				i_to_s_i(int **s, unsigned long long x, char *str, int minus)
{
	int				i;
	int				*new;
	int				d;

	i = 0;
	new = *s;
	d = 0;
	x == 0 ? (str[i++] = '0') : (str[i]);
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	new[2] == -2 ? (new[2] = -1) : (new[2]);
	if (minus == 1 && new[1] > new[2] + 1 + int_l(x) + 1 && f_f(new[0],
			2) > 0 && f_f(new[0], 3) <= 0)
		while (new[1]-- > new[2] + int_l(x) + 2)
			str[i++] = '0';
	if (minus == 1)
		str[i++] = '-';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

int				i_to_s(unsigned long long x, char *str, int d, int large)
{
	int				i;

	i = 0;
	if (x == 0)
		str[i++] = '0';
	if (large > 0)
		while (large-- > 0)
			str[i++] = '0';
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

long double		ft_pow_m(int x, int n)
{
	long double		ext;
	int				i;

	ext = 1;
	i = 1;
	while (i <= n)
	{
		ext *= x;
		i++;
	}
	return (ext);
}
