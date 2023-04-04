#include "../push_swap.h"

void	sa_command(t_list *stack_A)
{
	t_node	*first;
	t_node	*second;

	first = stack_A->head->to;
	second = stack_A->head->to->to;
	second->from = first->from;
	first->to = second->to;
	second->to = first;
	first->from = second;
	stack_A->head->to = second;
	printf("sa\n");
}

void	sb_command(t_list *stack_B)
{
	t_node	*first;
	t_node	*second;

	first = stack_B->head->to;
	second = stack_B->head->to->to;
	second->from = first->from;
	first->to = second->to;
	second->to = first;
	first->from = second;
	stack_B->head->to = second;
	printf("sb\n");
}

void	ss_command(t_list *stack_A, t_list *stack_B)
{
	sa_command(stack_A);
	sb_command(stack_B);
	printf("ss\n");
}
