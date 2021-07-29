/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_form_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:52:29 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:52:43 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			work_with_x(int **s, va_list ap, int read)
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
	count = ft_putnbr_base_c(d, 16);
	read = work_x_o_u(&new, d, count, 16);
	return (read);
}
