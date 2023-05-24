#include "../push_swap.h"

void	recursive_quick_sort(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	pivot;

	// lst_print(stack);
	pivot = (low + high) / 2;
	if (high - low + 1 <= 3)
	{
		under_three(stack, stack->head_b, high - low + 1, 'b');
		i = 0;
		while (i < high - low + 1)
		{
			pa_command(stack);
			ra_command(stack);
			i++;
		}
		return ;
	}
	else
	{
		i = high;
		while (i > pivot)
		{
			if (stack->head_b->to->val > pivot)
			{
				pa_command(stack);
				i--;
			}
			else
				rb_command(stack);
		}
		recursive_quick_sort(stack, low, pivot);
		while (i++ < high)
			pb_command(stack);
		recursive_quick_sort(stack, pivot + 1, high);
	}
}

void	over_seven(t_list *stack, size_t size)
{
	size_t	cnt;
	size_t	pivot;
	size_t	low;
	size_t	high;
	size_t	tmp;

	cnt = 0;
	low = 1;
	high = size;
	pivot = (high + low) / 2;
	while (cnt < pivot)
	{
		tmp = stack->head_a->to->val;
		if (tmp <= pivot)
		{
			pb_command(stack);
			cnt++;
		}
		else
			ra_command(stack);
	}
	// lst_print(stack);
	recursive_quick_sort(stack, low, pivot);
	// lst_print(stack);
	pivot = (high + low) / 2;
	cnt = pivot;
	while (cnt++ < high)
		pb_command(stack);
	recursive_quick_sort(stack, pivot + 1, high);
}
