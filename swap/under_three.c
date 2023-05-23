#include "../push_swap.h"

void	swap_three(t_list *stack, t_node *head, char which)
{
	if (head->to->val > head->to->to->val)
	{
		if (head->to->to->val > head->from->val)
		{
			command_s(stack, which);
			command_rr(stack, which);
		}
		else
		{
			if (head->to->val > head->from->val)
				command_r(stack, which);
			else
				command_s(stack, which);
		}
	}
	else
	{
		if (head->to->val > head->from->val)
			command_rr(stack, which);
		else
		{
			command_s(stack, which);
			command_r(stack, which);
		}
	}
}

void	under_three(t_list *stack_A, size_t size)
{
	if (size == 2)
	{
		if (stack_A->head_a->to->val > stack_A->head_a->to->to->val)
			sa_command(stack_A);
	}
	else if (size == 3)
		swap_three(stack_A, stack_A->head_a, 'a');
}

// from up to down if statement
// 3 2 1
// 3 1 2
// 2 1 3
// 2 3 1
// 1 3 2