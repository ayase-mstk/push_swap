#include "../push_swap.h"

void	lst_init(t_list *list)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	head->from = head;
	head->to = head;
	list->head = head;
	// return (list);
}

// head -> head
//		<- head
//  ^
//  |
// list