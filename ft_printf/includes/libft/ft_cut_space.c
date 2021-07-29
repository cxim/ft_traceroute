/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:30:14 by selly             #+#    #+#             */
/*   Updated: 2019/09/19 20:32:36 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cut_space(const char **s)
{
	const char	*new;
	int			count_spaces;

	new = *s;
	count_spaces = 0;
	while (*new == ' ')
	{
		new++;
		count_spaces++;
	}
	*s = new;
	return (count_spaces);
}
