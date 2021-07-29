/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:44:30 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 16:44:44 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_fprintf(char *file, const char *format, ...)
{
	va_list			ap;
	int				*conv;
	int				read_symbols;

	if (!format || !*format || !file || !*file)
		return (0);
	conv = ft_new_integer_list(8);
	if ((conv[7] = open(file, O_RDWR | O_CREAT)) < 0)
	{
		free(conv);
		conv = NULL;
		return (0);
	}
	va_start(ap, format);
	read_symbols = format_str(format, ap, &conv, 0);
	va_end(ap);
	close(conv[7]);
	free(conv);
	conv = NULL;
	return (read_symbols);
}

int			ft_vprintf(const char *format, va_list ap)
{
	int			*conv;
	int			read_symbols;

	if (!format || !*format)
		return (0);
	conv = ft_new_integer_list(8);
	conv[7] = -1;
	read_symbols = format_str(format, ap, &conv, 0);
	free(conv);
	conv = NULL;
	return (read_symbols);
}

int			ft_vfprintf(char *file, const char *format, va_list ap)
{
	int			*conv;
	int			read_symbols;

	if (!format || !*format || !file || !*file)
		return (0);
	conv = ft_new_integer_list(8);
	if ((conv[7] = open(file, O_WRONLY | O_TRUNC | O_CREAT)) < 0)
	{
		free(conv);
		conv = NULL;
		return (0);
	}
	read_symbols = format_str(format, ap, &conv, 0);
	close(conv[7]);
	free(conv);
	conv = NULL;
	return (read_symbols);
}
