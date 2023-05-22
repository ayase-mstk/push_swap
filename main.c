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
	size_t		i;
	char	**arg_string;

	if (ac <= 1)
		exit(EXIT_SUCCESS);
	//  ./push_swap "1 5 3 -1" "8" "3"に対応する読み取り方を考える
	arg_string = bring_argv_together(av);
	// おそらく、一度引数を一つの文字列にまとめてから、座標圧縮するのが良いかもしれない
	if (error(arg_string))
		return (0); // エラーなのかEXIT_SUCCESSなのか
	stack = lst_init();
	// ここで先に av の値を座標圧縮する
	order = coordinate(arg_string, ft_strptrlen(arg_string));
	i = 0;
	while (i < ft_strptrlen(arg_string))
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

// compile
// python3 push_swap_tester.py -l 3 -r 1 100
// cc -fsanitize=address main.c coordinate_compression.c error.c ft_pushswap.c command/*.c list/*.c swap/*.c libft/libft.a libftprintf/libftprintf.a -o push_swap

// there are two ways to keep track of the head of a doubly linked circular list
// 1. Place the sentinel node at the beginning (end) of the list so that it can be identified. <- this
// 2. Always store which element is at the beginning in a variable so that it can be identified.
