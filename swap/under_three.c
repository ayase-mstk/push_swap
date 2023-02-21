#include "../push_swap"
#include <bool.h>

bool	compare(node *a, node *b)
{

}

void	swap_three(list *stack_A, size_t size)
{
	node	*first;
	node	*second;
	node	*third;
	int		*order;

	order = coordinate(stack_A, size);
	if (stack_A->head->to->val > stack_A->head->to->to->val)
	{
		if (stack_A->head->to->to->val > stack_A->head->from->val)
		{
			// 3 2 1
		}
		else
		{
			if (stack_A->head->to->val > stack_A->head->from->val)
				// 3 1 2
			else
				// 2 1 3
		}
	}
	else
	{
		if (stack_A->head->to->val > stack_A->head->from->val)
			// 2 3 1
		else
			// 1 3 2
	}
}

void	under_three(list *stack_A, size_t size)
{
	if (size == 1)
	else if (size == 2)
	{
		if (stack_A->head->to->val > stack_A->head->to->to->val)
			sa_command(stack_A);
		else
			//nothing else
	}
	else
		swap_three(stack_A, size);
}