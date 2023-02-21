#include "command.h"

void	rra_command(list *stack_A)
{
	stack_A->head->from->to = stack_A->head->to;
	stack_A->head->to->from = stack_A->head->from;
	stack_A->head->from = stack_A->head->from->from;
	stack_A->head->to->from->from = stack_A->head;
	stack_A->head->to = stack_A->head->to->from;
	printf("rra\n");
}

void	rrb_command(list *stack_A)
{
	stack_B->head->from->to = stack_B->head->to;
	stack_B->head->to->from = stack_B->head->from;
	stack_B->head->from = stack_B->head->from->from;
	stack_B->head->to->from->from = stack_B->head;
	stack_B->head->to = stack_B->head->to->from;
	printf("rrb\n");
}

void	rrr_command(list *stack_A, list *stack_B)
{
	rra_command(stack_A);
	rrb_command(stack_B);
	printf("rrr\n");
}
