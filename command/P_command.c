#include "command_h"

void	pa_command(list *stack_A, list *stack_B)
{
	stack_B->head->to->to->from = stack_B->head;
	stack_A->head->to->from = stack_B->head->to;
	stack_A->head->to = stack_B->head->to;
	stack_B->head->to =stack_B->head->to->to;
	printf("pa\n");
}

void	pb_command(list *stack_A, list *stack_B)
{
	stack_A->head->to->to->from = stack_A->head;
	stack_B->head->to->from = stack_A->head->to;
	stack_B->head->to = stack_A->head->to;
	stack_A->head->to =stack_A->head->to->to;
	printf("pb\n");
}