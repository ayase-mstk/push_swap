#include "../push_swap.h"

static int	check_ascend(t_list *stack)
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
	if (cnt != 2)
		return (1);
	return (0);
}

static void	move_smlval(t_list *stack, t_node *tmp)
{
	if (tmp->val == stack->head_a->to->val || \
		tmp->val == stack->head_a->to->to->val)
	{
		while (stack->head_a->to->val != tmp->val)
			ra_command(stack);
	}
	else
	{
		while (stack->head_a->to->val != tmp->val)
			rra_command(stack);
	}
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
			if (tmp->val == (int)i)
			{
				move_smlval(stack, tmp);
				break ;
			}
			tmp = tmp->to;
		}
		i++;
	}
	if (check_ascend(stack))// ifnot ascending order
		under_three(stack, size - i + 1);
	while (i-- > 1)
		pa_command(stack);
}

// size-3個までの数字をstack_Aの小さいほうから順にstack_Bにpushする
// その後、stack_Aの数字を昇順に並べる
// その後、stack_Bの数字をstack_Aにpushする


// [OK]1832297563 675833010 -1725881118 -2140910522 -2145042879: 13
// [OK]-1725881118 1832297563 675833010 -2140910522 -2145042879: 13