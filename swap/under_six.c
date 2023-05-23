#include "../push_swap.h"

static int	check_ascend(t_list *stack, size_t size)
{
	size_t	cnt;
	t_node	*tmp;

	cnt = 0;
	tmp = stack->head_a->to;
	while (tmp->to != stack->head_a)
	{
		if (tmp->val < tmp->to->val)
			cnt++;
		tmp = tmp->to;
	}
	if (cnt != size - 1)
		return (1);
	return (0);
}

static void	move_smlval(t_list *stack, size_t num, size_t size)
{
	t_node	*tmp;
	size_t	cnt;

	cnt = 0;
	tmp = stack->head_a->to;
	while (tmp->val != num)
	{
		tmp = tmp->to;
		cnt++;
	}
	if (cnt <= size / 2)
	{
		while (stack->head_a->to->val != num)
		{
			if (stack->head_a->to->to->val == num)
				sa_command(stack);
			else
				ra_command(stack);
		}
	}
	else
		while (stack->head_a->to->val != num)
			rra_command(stack);
	pb_command(stack);
}

// stack->head_a->to->valがiと一致するまでstack_Aをra回転させる
// 一致したらpa_commandでstack_Aにpushする

void	under_six(t_list *stack, size_t size)
{
	size_t	i;
	t_node	*tmp;

	i = 1;
	while (i <= size - 3)
	{
		tmp = stack->head_a->to;
		while (tmp != stack->head_a)
		{
			if (tmp->val == i)
			{
				move_smlval(stack, i, size);
				break ;
			}
			tmp = tmp->to;
		}
		i++;
	}
	if (check_ascend(stack, 3))
		under_three(stack, 3);
	while (i-- > 1)
		pa_command(stack);
}

// push the numbers up to size-3 from the smaller one of stack_A to stack_B in order
// Then arrange the numbers in stack_A in ascending order
// Then push the numbers in stack_B to stack_A
