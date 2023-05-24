#include "../push_swap.h"

void	recursive_quick_sort(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	pivot;

	// lst_print(stack);
	pivot = (low + high) / 2;
	if (high - low + 1 <= 20)
	{
		pivot = high;
		while ((high--) - low + 1 > 3)
			move_smlval(stack, stack->head_b, high + 1, 'b');
		// lst_print(stack);
		ft_pushswap(stack, stack->head_b, 'b');
		i = 0;
		while (i <= high - low + 1)
		{
			pa_command(stack);
			ra_command(stack);
			i++;
		}
		// lst_print(stack);
		high = pivot;
		while ((high--) - low + 1 > 3)
			ra_command(stack);
		// lst_print(stack);
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
	t_node	*tmp;

	cnt = 0;
	low = 1;
	high = size;
	pivot = (high + low) / 2;
	while (cnt < pivot)
	{
		tmp = stack->head_a->to;
		if (tmp->val <= pivot)
		{
			pb_command(stack);
			cnt++;
		}
		else if (tmp->to->val == cnt + 1 && tmp->val == cnt + 2)
		{
			sa_command(stack);
			pb_command(stack);
			cnt++;
		}
		else
			ra_command(stack);
	}
	// lst_print(stack);
	recursive_quick_sort(stack, low, pivot);
	// lst_print(stack);
	// return ;
	pivot = (high + low) / 2;
	cnt = pivot;
	while (cnt++ < high)
		pb_command(stack);
	recursive_quick_sort(stack, pivot + 1, high);
}
