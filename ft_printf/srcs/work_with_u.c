/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:54:04 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:54:07 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			work_with_u(int **s, va_list ap, int read)
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
	count = ft_putnbr_base_c(d, 10);
	if (d == 0 && (new[2] == -3 || new[2] == -2) && new[1] <= 0)
		count = 0;
	read = work_x_o_u(&new, d, count, 10);
	return (read);
}
