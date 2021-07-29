/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:45:55 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:45:57 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			check_conv(const char **p)
{
	char			*format;
	const char		*new;
	int				format_id;
	int				result;

	format = "cspdiouxXf";
	new = *p;
	format_id = 0;
	if ((result = ft_char_in_string(*new, format)) > 0)
	{
		format_id *= 10;
		format_id += result;
		new++;
	}
	else if (format_id <= 0)
	{
		while (*new == ' ')
			new++;
	}
	*p = new;
	return (format_id);
}
