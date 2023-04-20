#include "../push_swap.h"

void	lst_pushback(t_list *list, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = value;
	new->from = list->head_a->from;
	new->to = list->head_a;
	list->head_a->from->to = new;
	list->head_a->from = new;
}
