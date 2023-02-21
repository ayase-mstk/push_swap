#include "push_swap.h"

int	main(int ac, char **av)
{
	list	stack_A;
    size_t  i;

	if (error(ac, av))
		write(2, "error\n", 6);
	lst_init(&stack_A);
    i = 1;
    while (i < ac)
    {
        lst_pushback(&stack_A, ft_atoi(av[i]));
		i++;
    }
	ft_pushswap(&stack_A);
	lst_print(&stack_A);
	lst_free(&stack_A);
	return (0);
}

// コンパイル
// cc -fsanitize=address main.c list/lst_init.c  list/lst_pushback.c  list/lst_print.c list/lst_free.c utils/ft_atoi.c utils/ft_isdigit.c 

// 双方向循環リストで先頭を保持する方法２つ
// 1.番兵ノードをリストの先頭（末尾）に配置して判別できるようにする☆
// 2.常に先頭の要素がどれかわかるように何かの変数に入れて保持する