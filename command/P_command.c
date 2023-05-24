#include "../push_swap.h"

void	pa_command(t_list *stack)
{
	t_node	*first;

	first = stack->head_b->to;
	stack->head_b->to = stack->head_b->to->to;
	first->to = stack->head_a->to;
	first->from = stack->head_a;
	stack->head_a->to = first;
	first->to->from = first;
	if (stack->head_a->from == stack->head_a)
		stack->head_a->from = first;
	ft_printf("pa\n");
}

void	pb_command(t_list *stack)
{
	t_node	*first;

	first = stack->head_a->to;
	stack->head_a->to = stack->head_a->to->to;
	first->to = stack->head_b->to;
	first->from = stack->head_b;
	stack->head_b->to = first;
	first->to->from = first;
	if (stack->head_b->from == stack->head_b)
		stack->head_b->from = first;
	ft_printf("pb\n");
}

void	command_p(t_list *stack, char which)
{
	if (which == 'a')
		pa_command(stack);
	else if (which == 'b')
		pb_command(stack);
}
