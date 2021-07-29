/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:53:32 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:53:37 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			work_with_o(int **s, va_list ap, int read)
{
	unsigned long long int		d;
	int							count;
	int							*new;

	new = *s;
	if (new[3] == 2)
		d = va_arg(ap, unsigned long int);
	else if (new[3] == 22)
		d = va_arg(ap, unsigned long long);
	else if (new[3] == 11)
		d = (unsigned char)va_arg(ap, unsigned int);
	else if (new[3] == 1)
		d = (unsigned short int)va_arg(ap, unsigned int);
	else
		d = va_arg(ap, unsigned int);
	count = ft_putnbr_base_c(d, 8);
	if (d == 0 && new[2] == -3 && f_f(new[0], 1) == 0 && new[1] <= 0)
		return (0);
	if (d == 0 && new[1] == 0 && new[2] == -2 && f_f(new[0], 1) == 0)
		return (0);
	read = work_x_o_u(&new, d, count, 8);
	return (read);
}
