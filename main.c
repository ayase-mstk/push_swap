#include "push_swap.h"

char **bring_argv_together(char **av)
{
	int		i;
	char	**arg_string;
	char	**arg_string_all;
	char	**tmp;


	i = 1;
	while (av[i])
	{
		arg_string = ft_split(av[i], ' ');
		tmp = arg_string_all;
		if (i == 1)
			arg_string_all = arg_string;
		else
			arg_string_all = ft_strptrjoin(tmp, arg_string);
		i++;
	}
	return (arg_string_all);
}

int	main(int ac, char **av)
{
	t_list	*stack;
	int		*order;
	int		i;
	char	**arg_string;

	if (ac <= 1)
		exit (EXIT_SUCCESS);
	//  ./push_swap "1 5 3 -1" "8" "3"に対応する読み取り方を考える
	arg_string = bring_argv_together(av);
	// おそらく、一度引数を一つの文字列にまとめてから、座標圧縮するのが良いかもしれない
	if (error(ac, arg_string))
		return (0); // エラーなのかEXIT_SUCCESSなのか
	stack = lst_init();
	// ここで先に av の値を座標圧縮する
	order = coordinate(ac, arg_string);
	i = 0;
	while (i < ac - 1)
	{
		lst_pushback(stack, order[i]);
		i++;
	}
	// lst_print(stack);
	ft_pushswap(stack);
	// lst_print(stack);
	lst_free(stack);
	return (0);
}

// __attribute__((destructor))
// void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

// コンパイル
// python3 push_swap_tester.py -l 3 -r 1 100
// cc -fsanitize=address main.c coordinate_compression.c error.c ft_pushswap.c command/*.c list/*.c swap/*.c libft/libft.a libftprintf/libftprintf.a -o push_swap


// 双方向循環リストで先頭を保持する方法２つ
// 1.番兵ノードをリストの先頭（末尾）に配置して判別できるようにする <- こっち
// 2.常に先頭の要素がどれかわかるように何かの変数に入れて保持する