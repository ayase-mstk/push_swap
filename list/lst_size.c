#include "double_list.h"

size_t	lst_size(list *list)
{
	size_t	size;
	node	*p;

	size = 0;
	p = list->head->to;
	while (p != list->head)
	{
		size++;
		p = p->to;
	}
	return (size);
}
