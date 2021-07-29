/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:33:26 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 17:40:40 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_integer(const char **p)
{
	int				result;
	int				i;
	const char		*num;

	i = 0;
	num = *p;
	ft_cut_space(&num);
	result = 0;
	while (*num >= '0' && *num <= '9')
	{
		i++;
		num++;
	}
	num = *p;
	while (*num >= '0' && *num <= '9')
	{
		result = (result == 0 && i >= 10) ? 10 : result * 10;
		result += ((*num) - '0');
		i--;
		num++;
	}
	*p = num;
	return (result);
}
