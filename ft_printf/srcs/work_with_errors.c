/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:33:00 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:50:06 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_warning(int warning)
{
	if (warning == 0)
		ft_printf("(output doesn't exist or an error occurred)");
	else if (warning == 1)
	{
		ft_printf("(output doesn't exist or an error occurred)");
		return (-1);
	}
	return (1);
}

void	print_err(int error)
{
	if (error == 0)
		ft_putstr("\rERROR! Malloc can`t give memory to string.\n");
	else if (error == 1)
		ft_putstr("\rERROR! Wrong type of format in ft_printf.\n");
	else if (error == 2)
		ft_putstr("\rERROR! Empty arguments to format."
			"Input valit args, please.\n");
	else
		ft_putstr("ERROR! Ooops.. Something going wrong.");
	exit(1);
}
