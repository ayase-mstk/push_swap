#include "../push_swap.h"

void	move_bigval(t_list *stack, t_node *head, size_t num, char which)
{
	size_t	cnt;
	size_t	size;
	t_node	*tmp;

	cnt = 0;
	size = lst_size(head);
	tmp = head->to;
	while (tmp->val != num)
	{
		tmp = tmp->to;
		cnt++;
	}
	if (cnt <= size / 2)
	{
		while (head->to->val != num)
		{
			if (head->to->to->val == num)
				command_s(stack, which);
			else
				command_r(stack, which);
		}
	}
	else
		while (head->to->val != num)
			command_rr(stack, which);
	command_p(stack, which);
}

void	under20(t_list *stack, size_t low, size_t high, char which)
{
	size_t	i;
	size_t	tmp;

	tmp = high;
	if (which == 'd')
		while (tmp-- > low)
			rrb_command(stack);
	while ((high--) - low + 1 > 3)
		move_bigval(stack, stack->head_b, high + 1, 'b');
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

size_t	recursive_quick_sort_else(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	pivot;

	i = high;
	pivot = (low + high) / 2;
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
	return (i);
}

void	recursive_quick_sort_super(t_list *stack, size_t high, size_t low, char which)
{
	size_t	i;
	size_t	pivot;

	pivot = (low + high) / 2;
	if (high - low + 1 <= 20)
	{
		under20(stack, low, high, which);
		return ;
	}
	else
	{
		i = recursive_quick_sort_else(stack, low, high);
		recursive_quick_sort(stack, low, pivot);
		while (i++ < high)
			pb_command(stack);
		recursive_quick_sort(stack, pivot + 1, high);
	}
}

void	send_to_b(t_list *stack, size_t low, size_t high, char *which)
{
	size_t	i;

	i = low;
	while (i <= high)
	{
		if (stack->head_a->to->val <= high)
		{
			pb_command(stack);
			if (low != 1 && ft_strncmp(which, "down", 2) == 0)
				rb_command(stack);
			i++;
		}
		else
			ra_command(stack);
	}
}

void	send_ascending_order2(t_list *stack, size_t low, size_t high, char *which)
{
	size_t pivot;

	pivot = (low + high) / 2;
	if (high - low + 1 <= 20)
	{
		send_to_b(stack, low, high, which);
		return ;
	}
	else
	{
		send_ascending_order2(stack, low, pivot, "down");
		send_ascending_order2(stack, pivot + 1, high, "up");
	}
}

void	over_seven_kai(t_list *stack, size_t size)
{
	// size_t	cnt;
	// size_t	pivot;
	size_t	low;
	size_t	high;

	low = 1;
	high = size;
	send_ascending_order2(stack, low, high, "up");
	lst_print(stack);
	return ;
	recursive_quick_sort_super(stack, high, low);
}