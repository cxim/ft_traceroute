/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:05:40 by selly             #+#    #+#             */
/*   Updated: 2019/10/28 18:01:36 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_mod(char const *str, int fd)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (fd < 0)
			ft_putchar(*str);
		else
			ft_putchar_fd(*str, fd);
		str++;
		i++;
	}
	return (i);
}
