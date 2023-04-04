#include "../push_swap.h"

void	lst_pushback(t_list *list, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = value;
	new->from = list->head->from;
	new->to = list->head;
	list->head->from->to = new;
	list->head->from = new;
}
