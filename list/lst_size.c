#include "../push_swap.h"

size_t	lst_size(t_list *list)
{
	size_t	size;
	t_node	*p;

	size = 0;
	p = list->head_a->to;
	while (p != list->head_a)
	{
		size++;
		p = p->to;
	}
	return (size);
}
