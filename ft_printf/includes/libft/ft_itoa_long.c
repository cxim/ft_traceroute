/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:41:11 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 17:47:30 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_delitel(unsigned long n)
{
	unsigned long		result;

	result = 1;
	while (n)
	{
		result *= 10;
		n--;
	}
	return (result);
}

static size_t			ft_chars(unsigned long n)
{
	size_t				i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char				*ft_getarray(char *ar, unsigned long n, int c, int a)
{
	while (c--)
	{
		ar[a] = n / ft_delitel(c) + '0';
		a++;
		n %= ft_delitel(c);
	}
	ar[a] = '\0';
	return (ar);
}

char					*ft_itoa_long(unsigned long n)
{
	size_t				chars;
	char				*new;

	chars = ft_chars(n);
	if (n == 0)
	{
		if (!(new = ft_strnew(1)))
			return (NULL);
		new[0] = '0';
		return (new);
	}
	if (!(new = ft_strnew(chars)))
		return (NULL);
	new = ft_getarray(new, n, chars, 0);
	return (new);
}
