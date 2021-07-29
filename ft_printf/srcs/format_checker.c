/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:26:06 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:45:46 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			check_flag(const char **p, int flag_id)
{
	char			*flags;
	int				is_space;
	int				result;
	const char		*new;

	flags = "#0-+ ";
	new = *p;
	is_space = ft_cut_space(&new);
	while ((result = ft_char_in_string(*new, flags)) > 0)
	{
		flag_id *= 10;
		flag_id += result;
		new++;
	}
	if (is_space > 0)
	{
		flag_id *= 10;
		flag_id += 5;
	}
	*p = new;
	return (flag_id);
}

int			check_accuracy_one(const char **p)
{
	const char	*new;
	int			result;

	new = *p;
	new++;
	if (*new >= '0' && *new <= '9')
	{
		result = ft_get_integer(&new);
		*p = new;
		return (result);
	}
	else
	{
		*p = new;
		return (-2);
	}
}

int			check_accuracy(const char **p)
{
	int				result;
	const char		*new;

	result = -1;
	new = *p;
	if (*new == '.')
	{
		new++;
		if (*new >= '0' && *new <= '9')
		{
			if (*new == '0')
			{
				result = check_accuracy_one(&new);
				*p = new;
				return (result);
			}
			result = ft_get_integer(&new);
		}
		else
			result = -3;
	}
	*p = new;
	return (result);
}

int			check_wight(const char **p)
{
	int				result;
	const char		*new;

	new = *p;
	result = ft_get_integer(&new);
	*p = new;
	return (result);
}

int			check_type(const char **p)
{
	char			*types;
	int				type_id;
	int				result;
	const char		*new;

	types = "hlL";
	new = *p;
	type_id = 0;
	while ((result = ft_char_in_string(*new, types)) > 0)
	{
		type_id *= 10;
		type_id += result;
		new++;
	}
	*p = new;
	return (type_id);
}
