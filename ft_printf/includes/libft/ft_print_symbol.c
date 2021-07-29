/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:24:17 by selly             #+#    #+#             */
/*   Updated: 2019/09/19 20:26:12 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_symbol(int i, char c, int fd)
{
	int		print;

	print = 0;
	while (i)
	{
		if (fd < 0)
			ft_putchar(c);
		else
			ft_putchar_fd(c, fd);
		i--;
		print++;
	}
	return (print);
}
