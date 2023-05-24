#include "../push_swap.h"

size_t	lst_size(t_node *head)
{
	size_t	size;
	t_node	*p;

	size = 0;
	p = head->to;
	while (p != head)
	{
		size++;
		p = p->to;
	}
	return (size);
}
