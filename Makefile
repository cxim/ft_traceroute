C_FLAGS =  -I
NAME = ft_traceroute
SRCS = main.c
#G_FLAGS = -Wall -Werror -Wextra
OBJECTS = $(SRCS:.c=.o)
LIBFT = ft_printf/
HEADER = ft_printf/includes
#HEAD = .
LIB = ft_printf/libftprintf.a


all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	gcc -o $(NAME) $(OBJECTS) $(LIB) -lm

$(OBJECTS):     %.o: %.c
	#clang -g  $(C_FLAGS) $(HEADER)  $(HEAD) -o $@ -c $<
	gcc -g  $(C_FLAGS) $(HEADER) -o $@ -c $<  #$(G_FLAGS)

clean:
	make clean -C $(LIBFT)
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re: fclean all