NAME = pushswap

SRCS = command/P_command.c command/R_command.c command/RR_command.c \
		command/S_command.c list/lst_free.c list/lst_init.c list/lst_print.c \
		list/lst_pushback.c list/lst_size.c swap/over_seven.c swap/under_six.c \
		swap/under_three.c utils/coordinate_compression.c utils/ft_atoi.c \
		utils/ft_isdigit.c ft_pushswap.c main.c

OBJS = $(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus