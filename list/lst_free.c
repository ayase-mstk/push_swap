#include "../push_swap.h"

void	lst_free(t_list *list)
{
	t_node	*a_ptr;
	t_node	*b_ptr;
	t_node	*next;

	a_ptr = list->head_a->to;
	b_ptr = list->head_b->to;
	while (a_ptr != list->head_a)
	{
		next = a_ptr->to;
		free(a_ptr);
		a_ptr = next;
	}
	free(list->head_a);
	while (b_ptr != list->head_b)
	{
		next = b_ptr->to;
		free(b_ptr);
		b_ptr = next;
	}
	free(list->head_b);
}
