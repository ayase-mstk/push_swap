#include "../push_swap.h"

void	sa_command(t_list *stack_A)
{
	t_node	*first;
	t_node	*second;

	first = stack_A->head->to;
	second = stack_A->head->to->to;
	second->from = stack_A->head;
	first->to = second->to;
	second->to = first;
	first->from = second;
	first->to->from = first;
	stack_A->head->to = second;
	printf("sa\n");
}

void	sb_command(t_list *stack_B)
{
	t_node	*first;
	t_node	*second;

	first = stack_B->head->to;
	second = stack_B->head->to->to;
	second->from = stack_B->head;
	first->to = second->to;
	second->to = first;
	first->from = second;
	first->to->from = first;
	stack_B->head->to = second;
	printf("sb\n");
}

void	ss_command(t_list *stack_A, t_list *stack_B)
{
	sa_command(stack_A);
	sb_command(stack_B);
	printf("ss\n");
}
