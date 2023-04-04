#include "push_swap.h"

void	ft_pushswap(t_list *stack_A)
{
	size_t	size;

	size = lst_size(stack_A);
	if (size <= 3)
		under_three(stack_A, size);
	// else if (size <= 6)
	// 	under_six(stack_A, size);
	// else
	// 	over_seven(stack_A, size);
}
