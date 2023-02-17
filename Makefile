NAME = pushswap.a

SRCS = 

OBJS = $(SRCS:%.c=%.o)

BONUS = 

BONUS_OBJS = $(BONUS:%.c=%.o)

LIB = libft/

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar crs

ARFLAGS = rs

ifdef WITH_BONUS
	SRCS += $(BONUS)
	OBJS += $(BONUS_OBJS)
endif

all:	$(NAME)

$(NAME): $(OBJS)
	make all -C $(LIB)
	cp $(LIB)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus:
	make WITH_BONUS=1

clean:
	make fclean -C $(LIB)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus