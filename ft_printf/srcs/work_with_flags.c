/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:35:54 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:51:45 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			all_flags(int *s)
{
	char	type;
	int		error;

	error = 0;
	type = s[4];
	if (type == 2)
	{
		if (f_f(s[4], 1) && s[3] != 0)
			error += print_warning(0);
		if (f_f(s[0], 1))
			error += print_warning(0);
		if (f_f(s[0], 2))
			error += print_warning(0);
		if (f_f(s[0], 4))
			error += print_warning(0);
		if (f_f(s[0], 5))
			error += print_warning(0);
		if (error > 0)
			return (-1);
	}
	return (0);
}

void		print_last_spaces(int **num, int flag, int len)
{
	int		*new;
	int		spaces;

	new = *num;
	if (flag == 1)
	{
		spaces = new[5];
		if (new[6] == -1)
			while (spaces-- > 0)
				ft_putchar_mod(' ', *num);
		new[6] = 1;
		new[5] = 0;
	}
	if (flag == 2)
	{
		if (f_f(new[0], 3) && len < new[1] && new[1] != 0)
		{
			if (new[6] == -1)
				new[5] = 0;
			new[6] = -1;
			new[5] = new[1] + new[5] - len;
			if (new[2] > len && new[4] != 2)
				new[5] += len - new[2];
		}
	}
}

int			f_f(int flags, int flag_id)
{
	while (flags)
	{
		if (flags % 10 == flag_id)
			return (1);
		flags /= 10;
	}
	return (0);
}
