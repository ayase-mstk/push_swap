#include "../push_swap.h"

void	lst_free(t_list *list)
{
	t_node	*p;
	t_node	*next;

	p = list->head->to;
	while (p != list->head)
	{
		next = p->to;
		free(p);
		p = next;
	}
	free(list->head);
}
