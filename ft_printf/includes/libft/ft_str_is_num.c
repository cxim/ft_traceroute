/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:13:22 by selly             #+#    #+#             */
/*   Updated: 2020/02/19 18:13:29 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(const char *str)
{
	int cur;

	cur = 0;
	if (!(ft_strchr("+-", str[cur])) && !(ft_isdigit(str[cur])))
		return (0);
	if (ft_strchr("+-", str[cur]) && !(ft_isdigit(str[cur + 1])))
		return (0);
	while (str[++cur])
		if (!(ft_isdigit(str[cur])))
			return (0);
	return (1);
}
