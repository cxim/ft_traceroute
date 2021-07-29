/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:46:13 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/02/21 16:57:22 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(char const *s)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	while (is_space(*s))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (*s == '+' && sign == 1)
		s++;
	while (*s >= '0' && *s <= '9' && num > -2147483648 && num < 2147483647)
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num * sign);
}
