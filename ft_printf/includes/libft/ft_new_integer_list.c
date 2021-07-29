/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_integer_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:37:09 by selly             #+#    #+#             */
/*   Updated: 2019/09/30 13:04:47 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_new_integer_list(int n)
{
	int			i;
	int			*new;

	if (!(new = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	i = 0;
	while (i < n)
		new[i++] = 0;
	new[2] = -1;
	return (new);
}
