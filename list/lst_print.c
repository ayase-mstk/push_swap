#include "double_list.h"

void	lst_print(list *list)
{
	node	*p;

	p = list->head->to;
	while (p != list->head)
	{
		printf("%d\n", p->val);  //後でft_printfにする
		p = p->to;
	}
}