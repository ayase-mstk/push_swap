#include "../push_swap.h"

void	pa_command(t_list *stack)
{
	stack->head_b->to->to->from = stack->head_b;
	stack->head_a->to->from = stack->head_b->to;
	stack->head_a->to = stack->head_b->to;
	stack->head_b->to =stack->head_b->to->to;
	printf("pa\n");
}

void	pb_command(t_list *stack)
{
	stack->head_a->to->to->from = stack->head_a;
	stack->head_b->to->from = stack->head_a->to;
	stack->head_b->to = stack->head_a->to;
	stack->head_a->to =stack->head_a->to->to;
	printf("pb\n");
}
