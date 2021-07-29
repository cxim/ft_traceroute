/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:16:39 by selly             #+#    #+#             */
/*   Updated: 2020/02/19 18:19:02 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsplit_len(char **str)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	tmp = str;
	i = 0;
	if (tmp == NULL)
		return (0);
	else
		while (tmp[i] != NULL)
			i++;
	return (i);
}
