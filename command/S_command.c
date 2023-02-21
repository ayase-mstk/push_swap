#include "command_h"

void	sa_command(list *stack_A)
{
	node *first;
	node *second;

	first = stack_A->head->to;
	second = stack_A->head->to->to;
	second->from = first->from;
	first->to = second->to;
	second->to = first;
	first->from = second;
	printf("sa\n"):
}

void	sb_command(list *stack_B)
{
	node *first;
	node *second;

	first = stack_B->head->to;
	second = stack_B->head->to->to;
	second->from = first->from;
	first->to = second->to;
	second->to = first;
	first->from = second;
	printf("sb\n"):
}

void	ss_command(list *stack_A, list *stack_B)
{
	sa_command(list *stack_A);
	sb_command(list *stack_B);
	printf("ss\n"):
}
