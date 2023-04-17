#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		*order;
	int		i;

	if (ac == 1)
		exit (EXIT_SUCCESS);
	if (error(ac, av) == 1)
		return (0); // エラーなのかEXIT_SUCCESSなのか
	stack_a = lst_init();
	// ここで先に av の値を座標圧縮する
	order = coordinate(ac, av);
	i = 0;
	while (i < ac - 1)
	{
		lst_pushback(stack_a, order[i]);
		i++;
	}
	// lst_print(&stack_a);
	ft_pushswap(stack_a);
	// lst_print(&stack_a);
	lst_free(stack_a);
	return (0);
}

// __attribute__((destructor))
// void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

// コンパイル
// python3 push_swap_tester.py -l 3 -r 1 100
// cc -fsanitize=address main.c coordinate_compression.c ft_pushswap.c list/lst_init.c  list/lst_pushback.c  list/lst_print.c list/lst_free.c

// 双方向循環リストで先頭を保持する方法２つ
// 1.番兵ノードをリストの先頭（末尾）に配置して判別できるようにする <- こっち
// 2.常に先頭の要素がどれかわかるように何かの変数に入れて保持する