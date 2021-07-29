# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selly <selly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 14:25:01 by selly             #+#    #+#              #
#    Updated: 2019/10/28 18:19:41 by mnarwhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT = includes/libft
DIR_S = srcs
DIR_O = objs
HEADER = includes
SOURCES = ft_printf.c                      \
    format_checker.c                 \
    work_with_errors.c               \
    work_with_flags.c                \
    work_with_format_char_str.c      \
    work_with_int.c\
    work_with_floats.c \
    work_with_form_x.c \
    work_with_x_big.c \
    work_with_o.c \
    work_with_u.c \
    work_with_p.c \
    base_n_p.c \
    print_some_wight_aruc.c \
    work_with_uxo_part_one.c \
    work_with_uxo_part_two.c \
    bonus_color.c \
    bonus_fd.c \
    color_option.c \
    bonus_smile.c \
    format_checker_one.c \
    ft_printf_one.c \
    work_with_f_one.c \
    work_with_f_two.c \
    work_with_f_three.c \
    work_uxo_po_one.c \
    work_uxo_po_two.c \
    work_uxo_pt_one.c \
    work_i_one.c \
    work_i_two.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
all: $(NAME)
$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp includes/libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
re: fclean all
