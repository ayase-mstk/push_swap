#include "double_list.h"

void	lst_pushback(list *list, int value)
{
    node	*new;


	new = (node *)malloc(sizeof(node));
    new->val = value;
	new->from = list->head->from;
	new->to = list->head;
	list->head->from->to = new;
	list->head->from = new;
}