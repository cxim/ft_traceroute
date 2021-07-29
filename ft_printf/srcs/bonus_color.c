/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:44:00 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:44:20 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			another_color(const char **p, int flag)
{
	int		i;

	if ((i = find_id(&(*p), "yellow")) == 1)
		start("1;33m", flag);
	else if ((i = find_id(&(*p), "Lred")) == 1)
		start("1;31m", flag);
	else if ((i = find_id(&(*p), "Lgreen")) == 1)
		start("1;32m", flag);
	else if ((i = find_id(&(*p), "Lgray")) == 1)
		start("1;37m", flag);
	else if ((i = find_id(&(*p), "Dgray")) == 1)
		start("1;30m", flag);
	else if ((i = find_id(&(*p), "Lblue")) == 1)
		start("1;34m", flag);
	else if ((i = find_id(&(*p), "Lpurple")) == 1)
		start("1;35m", flag);
	else if ((i = find_id(&(*p), "Lcyan")) == 1)
		start("1;36m", flag);
	else if ((i = find_id(&(*p), "white")) == 1)
		start("1;37m", flag);
	else
		return (0);
	return (i);
}

int			another_background(const char **p, int flag)
{
	int		i;

	if ((i = find_id(&(*p), "yellow")) == 1)
		start("1;43m", flag);
	else if ((i = find_id(&(*p), "Lgreen")) == 1)
		start("1;42m", flag);
	else if ((i = find_id(&(*p), "Lblue")) == 1)
		start("1;44m", flag);
	else if ((i = find_id(&(*p), "Lpurple")) == 1)
		start("1;45m", flag);
	else if ((i = find_id(&(*p), "Lcyan")) == 1)
		start("1;46m", flag);
	else if ((i = find_id(&(*p), "white")) == 1)
		start("1;47m", flag);
	else if ((i = find_id(&(*p), "Lgray")) == 1)
		start("47m", flag);
	else if ((i = find_id(&(*p), "Dgray")) == 1)
		start("1;40m", flag);
	else if ((i = find_id(&(*p), "Lred")) == 1)
		start("1;41m", flag);
	else
		return (0);
	return (i);
}

int			choose_color(const char **p)
{
	int		flag;
	int		i;

	flag = find_decor(&(*p));
	if ((i = find_id(&(*p), "red")) == 1)
		start("31m", flag);
	else if ((i = find_id(&(*p), "black")) == 1)
		start("30m", flag);
	else if ((i = find_id(&(*p), "green")) == 1)
		start("32m", flag);
	else if ((i = find_id(&(*p), "brown")) == 1)
		start("33m", flag);
	else if ((i = find_id(&(*p), "blue")) == 1)
		start("34m", flag);
	else if ((i = find_id(&(*p), "purple")) == 1)
		start("35m", flag);
	else if ((i = find_id(&(*p), "cyan")) == 1)
		start("36m", flag);
	else
		return (another_color(&(*p), flag));
	return (i);
}

int			choose_background(const char **p)
{
	int		flag;
	int		i;

	flag = find_decor(&(*p));
	if ((i = find_id(&(*p), "red")) == 1)
		start("41m", flag);
	else if ((i = find_id(&(*p), "black")) == 1)
		start("40m", flag);
	else if ((i = find_id(&(*p), "green")) == 1)
		start("42m", flag);
	else if ((i = find_id(&(*p), "brown")) == 1)
		start("43m", flag);
	else if ((i = find_id(&(*p), "blue")) == 1)
		start("44m", flag);
	else if ((i = find_id(&(*p), "purple")) == 1)
		start("45m", flag);
	else if ((i = find_id(&(*p), "cyan")) == 1)
		start("46m", flag);
	else
		return (another_background(&(*p), flag));
	return (i);
}

int			get_color(const char **p)
{
	int		i;

	(*p)++;
	if ((i = find_id(&(*p), "eoc")) == 1)
		ft_putstr("\e[0m");
	else if ((i = find_id(&(*p), "font")) == 1)
		i = choose_color(&(*p));
	else if ((i = find_id(&(*p), "back")) == 1)
		choose_background(&(*p));
	else
		i = choose_color(&(*p));
	return (i);
}
