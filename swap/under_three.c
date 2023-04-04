#include "../push_swap.h"

void	swap_three(t_list *stack_A)
{
	if (stack_A->head->to->val > stack_A->head->to->to->val)
	{
		if (stack_A->head->to->to->val > stack_A->head->from->val) // 3 2 1
		{
			sa_command(stack_A);
			rra_command(stack_A);
		}
		else
		{
			if (stack_A->head->to->val > stack_A->head->from->val) // 3 1 2
				ra_command(stack_A);
			else // 2 1 3
				sa_command(stack_A);
		}
	}
	else
	{
		if (stack_A->head->to->val > stack_A->head->from->val) // 2 3 1
			rra_command(stack_A);
		else // 1 3 2
		{
			sa_command(stack_A);
			ra_command(stack_A);
		}
	}
}

void	under_three(t_list *stack_A, size_t size)
{
	if (size == 2)
	{
		if (stack_A->head->to->val > stack_A->head->to->to->val)
			sa_command(stack_A);
	}
	else if (size == 3)
		swap_three(stack_A);
}
