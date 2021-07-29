/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:40:41 by mnarwhal          #+#    #+#             */
/*   Updated: 2019/09/04 13:40:45 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (tab && f)
	{
		while (tab[i] != 0)
		{
			if (f(tab[i]))
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}
