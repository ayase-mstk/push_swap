#include "double_list.h"

void	lst_init(list *list)
{
	node	*head;

	head = (node *)malloc(sizeof(node));
	head->from = head;
	head->to = head;
	list->head = head;
	// return (list);
}