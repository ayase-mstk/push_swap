#include "push_swap.h"

int	already_swapped(t_node *head)
{
	size_t	cnt;
	t_node	*tmp;

	cnt = 0;
	tmp = head->to;
	while (tmp->to != head)
	{
		if (tmp->val < tmp->to->val)
			cnt++;
		tmp = tmp->to;
	}
	if (cnt == lst_size(head) - 1)
		return (1);
	return (0);
}

void	ft_pushswap(t_list *stack, t_node *head, char which)
{
	size_t	size;

	size = lst_size(head);
	if (size <= 3)
		under_three(stack, head, size, which);
	else if (size <= 6)
		under_six(stack, head, size, which);
	else
		over_seven(stack, size);
}
