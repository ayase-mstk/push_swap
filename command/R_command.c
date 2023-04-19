#include "../push_swap.h"

void	ra_command(t_list *stack_A)
{
	stack_A->head_a->to->from = stack_A->head_a->from;
	stack_A->head_a->from->to = stack_A->head_a->to;
	stack_A->head_a->to = stack_A->head_a->to->to;
	stack_A->head_a->from->to->to = stack_A->head_a;
	stack_A->head_a->from = stack_A->head_a->from->to;
	printf("ra\n");
}

void	rb_command(t_list *stack_B)
{
	stack_B->head_b->to->from = stack_B->head_b->from;
	stack_B->head_b->from->to = stack_B->head_b->to;
	stack_B->head_b->to = stack_B->head_b->to->to;
	stack_B->head_b->from->to->to = stack_B->head_b;
	stack_B->head_b->from = stack_B->head_b->from->to;
	printf("ra\n");
	printf("rb\n");
}

void	rr_command(t_list *stack_A, t_list *stack_B)
{
	ra_command(stack_A);
	rb_command(stack_B);
	printf("rr\n");
}
