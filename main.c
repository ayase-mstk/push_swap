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
	arg_string = bring_argv_together(av);
	if (error(arg_string))
		return (0); // エラーなのかEXIT_SUCCESSなのか
	stack = lst_init();
	order = coordinate(arg_string, ft_strptrlen(arg_string));
	i = 0;
	while (i < ft_strptrlen(arg_string))
	{
		lst_pushback(stack, (size_t)order[i]);
		i++;
	}
	free(order);
	// lst_print(stack);
	ft_pushswap(stack, stack->head_a, 'a');
	// lst_print(stack);
	// lst_free(stack);
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

// finish case == under 4
// max   : 977
// median: 957
// min   : 935
// finish case == under 5
// max   : 973
// median: 957
// min   : 939
// finish case == under 6
// max   : 912
// median: 891
// min   : 864
// finish case == under 8
// max   : 886
// median: 866
// min   : 847
// finish case == under 10
// max   : 884
// median: 865
// min   : 843
// finish case == under 15
// max   : 843
// median: 808
// min   : 776
// finish case == under 16
// max   : 839 5830
// median: 808 5736
// min   : 776 5627
// finish case == under 18
// max   : 838
// median: 806
// min   : 773
// finish case == under 19
// max   : 846
// median: 807
// min   : 766
// finish case == under 20
// max   : 833 5806
// median: 805 5734
// min   : 770 5638
// finish case == under 25
// max   : 881
// median: 821
// min   : 771
// finish case == under 50
// max   : 1113
// median: 985
// min   : 878