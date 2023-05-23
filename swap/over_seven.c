#include "../push_swap.h"

// void	move_smlval_to_b(t_list *stack, size_t num)
// {
// 	t_node	*tmp;

// 	tmp = stack->head_a->to;
// 	while (tmp != stack->head_a)
// 	{
// 		if (tmp->val == num)
// 		{
// 			pb_command(stack);
// 			break ;
// 		}
// 		else
// 			ra_command(stack);
// 		tmp = tmp->to;
// 	}
// }

void	recursive_quick_sort(t_list *stack, size_t pivot)
{
	size_t	tmp_pivot;

	tmp_pivot = pivot;
	if (pivot <= 1)
		return ;
	if (pivot <= 3)
	{
		swap_three(stack, stack->head_b, 'b');
		while (pivot--)
		{
			pa_command(stack);
			ra_command(stack);
		}
		return ;
	}
	else
	{
		while (tmp_pivot--)
			pa_command(stack);
		recursive_quick_sort(stack, pivot / 2);
		while (pivot--)
			rb_command(stack);
	}
}

void	over_seven(t_list *stack, size_t size)
{
	size_t	i;
	size_t	pivot;
	t_node	*tmp;

	i = 0;
	while (i < 2)
	{
		pivot = size / 2;
		tmp = stack->head_a->to;
		while (pivot--)
		{
			if (tmp->val < pivot)
				pb_command(stack);
			else
				ra_command(stack);
			tmp = tmp->to;
		}
		recursive_quick_sort(stack, pivot);
		i++;
	}
}
