#include "double_list.h"

void	lst_free(list *list)
{
	node	*p;
	node	*next;
	
	p = list->head->to;
	while (p != list->head)
	{
		next = p->to;
		free(p);
		p = next;
	}
	free(list->head);
}