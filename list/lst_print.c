#include "../push_swap.h"

void	lst_print(t_list *list)
{
	t_node	*a_ptr;

	a_ptr = list->head_a->to;
	while (a_ptr != list->head_a)
	{
		ft_printf("%d\n", a_ptr->val);
		a_ptr = a_ptr->to;
	}
}
