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


// 7 3 1 6 5 4 2
// 3 1 4 7 6 5 2
// 4 7 3 6 5 1 2
// 1 7 2 4 6 5 3
// 6 4 2 5 3 1 7
// 2037903686 1224654954 628164785 -550222900 739221339 912389303 -1574986904
// -1144795999 2100183428 1302300857 1619205134 1803377284 1715710127 -759416203
// -397902161 1734692458 -126907870 217714719 -2119253549 -348563280 1743889974
// 1502079260 -670953298 -799188922 -1557451304 395530980 -1584226763 1640009114
// 1647563336 -1492259754 249602482 -123524202 -824674640 -1139709998 -1643931335
// 1986261468 1878105464 620750841 1410840248 -132462455 -495195640 -765397055
// -2105220086 911231606 534136008 -626929341 -839740694 286892981 86561759
// -726833298 638908033 -1797450523 -90029562 -155767973 -1424101330 -1574513163
// -850530484 -1652128055 786900215 -770383046 1910203200 1389978687 795168826
// 42690126 1687418038 -1510848983 566481809 -1270242430 -2058118979 2017482382
// 1913321787 1340187905 -328172504 812203636 361257142 -1204557064 -971958294
// 1959232714 -1767037633 1433610734 1383901037 -156385560 623324043 646808422
// 2111806170 -701631057 871435453 741078322 -689012736 -1595702626 -1449098451
// 1627317404 429777242 -719450033 -250810423 -2143808608 -1104886338 2075506081
// -1190295726 -574015010 -1734647909 298575444 -146629098 -1687766705 1789873016
// -194983480 992351467 -503533773 737866583 -1232218572 1214835607 996482127
// 