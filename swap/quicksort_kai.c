#include "../push_swap.h"

static void	recursive_quick_sort_under20(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	tmp;

	tmp = high;
	while ((high--) - low + 1 > 3)
		move_smlval(stack, stack->head_b, high + 1, 'b');
	ft_pushswap(stack, stack->head_b, 'b');
	i = 0;
	while (i <= high - low + 1)
	{
		pa_command(stack);
		ra_command(stack);
		i++;
	}
	high = tmp;
	while ((high--) - low + 1 > 3)
		ra_command(stack);
}

static size_t recursive_quick_sort_else1(t_list *stack, size_t pivot2, size_t high)
{
	while (high > pivot2)
	{
		if (stack->head_b->to->val > pivot2)
		{
			pa_command(stack);
			ra_command(stack);
			high--;
		}
		else
			rb_command(stack);
	}
	return (high);
}

static size_t	recursive_quick_sort_else2(t_list *stack, size_t pivot1, size_t pivot2)
{
	while (pivot2 > pivot1)
	{
		if (stack->head_b->to->val > pivot1)
		{
			pa_command(stack);
			pivot2--;
		}
		else
			rb_command(stack);
	}
	return (pivot2);
}

void	recursive_quick_sort_kai(t_list *stack, size_t low, size_t high)
{
	lst_print(stack);
	size_t	i;
	size_t	j;
	size_t	pivot1;
	size_t	pivot2;

	pivot1 = (low + high) / 3;
	pivot2 = pivot1 * 2;
	if (high - low + 1 <= 20)
	{
		recursive_quick_sort_under20(stack, low, high);
		return ;
	}
	else
	{
		i = recursive_quick_sort_else1(stack, pivot2, high);
		j = recursive_quick_sort_else2(stack, pivot1, pivot2);
		recursive_quick_sort_kai(stack, low, pivot1);
		while (i++ < pivot2)
			pb_command(stack);
		recursive_quick_sort_kai(stack, pivot1 + 1, pivot2);
		while (j++ < high)
		{
			rra_command(stack);
			pb_command(stack);
		}
		recursive_quick_sort_kai(stack, pivot2 + 1, high);
	}
}
