#include "../push_swap.h"

void	rra_command(t_list *stack_A)
{
	stack_A->head_a->from->to = stack_A->head_a->to;
	stack_A->head_a->to->from = stack_A->head_a->from;
	stack_A->head_a->from = stack_A->head_a->from->from;
	stack_A->head_a->to->from->from->to = stack_A->head_a;
	stack_A->head_a->to = stack_A->head_a->to->from;
	stack_A->head_a->to->from = stack_A->head_a;
	ft_printf("rra\n");
}

void	rrb_command(t_list *stack_B)
{
	stack_B->head_b->from->to = stack_B->head_b->to;
	stack_B->head_b->to->from = stack_B->head_b->from;
	stack_B->head_b->from = stack_B->head_b->from->from;
	stack_B->head_b->to->from->from->to = stack_B->head_b;
	stack_B->head_b->to = stack_B->head_b->to->from;
	stack_B->head_b->to->from = stack_B->head_b;
	ft_printf("rrb\n");
}

void	rrr_command(t_list *stack_A, t_list *stack_B)
{
	rra_command(stack_A);
	rrb_command(stack_B);
	ft_printf("rrr\n");
}
