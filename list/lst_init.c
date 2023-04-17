#include "../push_swap.h"

t_list	*lst_init()
{
	t_list	*list;
	t_node	*head;

	list = (t_list *)malloc(sizeof(t_list));
	head = (t_node *)malloc(sizeof(t_node));
	head->from = head;
	head->to = head;
	list->head = head;
	return (list);
}

// head -> head
//		<- head
//  ^
//  |
// list