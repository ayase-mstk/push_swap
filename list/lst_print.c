#include "../push_swap.h"

void	lst_print(t_list *list)
{
	t_node	*p;

	p = list->head->to;
	while (p != list->head)
	{
		printf("%d\n", p->val);  //後でft_printfにする
		p = p->to;
	}
}
