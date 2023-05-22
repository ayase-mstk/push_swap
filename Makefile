NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f
LIBFT_DIR  = libft
PRINTF_DIR = libftprintf
LIBS       = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

SRCS = 	command/P_command.c \
		command/R_command.c \
		command/RR_command.c \
		command/S_command.c \
		list/lst_free.c \
		list/lst_init.c \
		list/lst_print.c \
		list/lst_pushback.c \
		list/lst_size.c \
		swap/over_seven.c \
		swap/under_six.c \
		swap/under_three.c \
		coordinate_compression.c \
		ft_pushswap.c \
		error.c \
		main.c

OBJS = $(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re