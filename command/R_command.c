#include "../push_swap.h"

void	ra_command(t_list *stack_A)
{
	stack_A->head->to->from = stack_A->head->from;
	stack_A->head->from->to = stack_A->head->to;
	stack_A->head->to = stack_A->head->to->to;
	stack_A->head->from->to->to = stack_A->head;
	stack_A->head->from = stack_A->head->from->to;
	printf("ra\n");
}

void	rb_command(t_list *stack_B)
{
	stack_B->head->to->from = stack_B->head->from;
	stack_B->head->from->to = stack_B->head->to;
	stack_B->head->to = stack_B->head->to->to;
	stack_B->head->from->to->to = stack_B->head;
	stack_B->head->from = stack_B->head->from->to;
	printf("ra\n");
	printf("rb\n");
}

void	rr_command(t_list *stack_A, t_list *stack_B)
{
	ra_command(stack_A);
	rb_command(stack_B);
	printf("rr\n");
}
