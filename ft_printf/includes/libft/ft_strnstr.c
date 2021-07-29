/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:51:49 by mnarwhal          #+#    #+#             */
/*   Updated: 2019/09/09 12:52:49 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *lstr, const char *sstr, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while ((i < len) && (lstr[i] != '\0') && (sstr[j] != '\0'))
	{
		if (lstr[i] == sstr[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (sstr[j] != '\0')
		return (NULL);
	else
		return ((char*)&lstr[i - j]);
}
