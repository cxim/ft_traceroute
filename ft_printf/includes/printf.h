/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:11:28 by selly             #+#    #+#             */
/*   Updated: 2019/11/07 17:35:27 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "libft/libft.h"

int				ft_printf(const char *format, ...);
int				format_str(const char *form, va_list ap, int **c, int s);
int				check_flag(const char **p, int flag_id);
int				check_wight(const char **p);
int				check_accuracy(const char **p);
int				check_type(const char **p);
int				check_conv(const char **p);
int				format_args(int **s, va_list ap);
int				read_conv(va_list ap, const char **p, int **s, int end);
int				format_args(int **s, va_list ap);
int				read_conv(va_list ap, const char **p, int **s, int end);
int				work_with_chars(int **s, va_list ap, int read, char *empty);
int				work_with_pointer(int **s, va_list ap, int read);
int				work_with_int(int **s, va_list ap, int read, char *flag);
int				work_with_o(int **s, va_list ap, int read);
int				work_with_x(int **s, va_list ap, int read);
int				work_with_x_big(int **s, va_list ap, int read);
int				work_with_u(int **s, va_list ap, int read);
int				work_with_floats(int **s, va_list ap, int read);
int				f_f(int flags, int flag_id);
void			print_percent(int *read, int spaces, int i, int fd);
void			find_doubles(const char **p, int *i, int *spaces);
int				int_l(unsigned long int n);
int				i_to_s_i(int **s, unsigned long long x, char *str, int minus);
int				i_to_s(unsigned long long x, char *str, int d, int large);
long double		ft_pow_m(int x, int n);
char			*ft_ftoa(int **s, long double n, int after_p, int minus);
void			out_zero_float_one(int **s, char *str, int sight);
void			out_zero_float_two(int **s, char *str, int sight, int len);
void			out_zero_float_three(int **s, char *str, int sight, int len);
int				out_zero_float(int **s, char *str, int sight);
int				float_wight_more(int **s, int len, char *str, int sight);
void			write_o_x_o(int **s);
void			wight_or_acur_three(int **s, int *count, int *c);
int				a_print(int *new, int d, char *str, int count);
int				print_prefix_1(int times, char prefix, int *n);
int				general_wigt_ac(int **s, int d, int *w, char *str);
void			print_last_spaces(int **num, int flag, int len);
char			*read_num(int *s, va_list ap, int *flag);
int				all_flags(int *s);
int				print_warning(int warning);
void			ft_pn_base_p(unsigned long long n, int b, int fl, int *s);
int				ft_putnbr_base_c(unsigned long long nbr, int base);

void			write_new_one(int i, int *n);
void			if_minus_off_part_two(int **s, unsigned long d, int count);
void			if_minus_off_part_one(int **s, unsigned long d, int count);
int				true_score(int **s, unsigned long d, int count, int base);
int				if_flags_more_d(int **s, unsigned long d, int count, int base);
int				if_wight_more_acur(int **s, unsigned long d, int c, int base);
int				if_minus_in_flag_off(int **s, unsigned long d, int c, int base);
int				if_minus_in_flag_on(int **s, unsigned long d, int c, int base);
int				wight_more_count(int **s, unsigned long d, int count, int base);
int				wight_or_acur(int **s, unsigned long d, int count, int base);
int				wight_or_acur_two(int **s, unsigned long d, int c, int base);
int				work_x_o_u(int **s, unsigned long d, int count, int base);

int				get_bonus(const char **p);
int				get_color(const char **p);
int				find_id(const char **p, const char *end);
int				find_decor(const char **p);
void			start(char *str, int flag);
int				ft_fprintf(char *file, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);

#endif
