#include ""

void	move_sval(t_list)
{

}

void	under_six(t_list *stack_A, size_t size)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = stack_A->head->to;
	size = (size + 1) / 2;
	while (tmp != stack_A->head)
	{
		if (tmp->val <= size)
			move_sval();
		tmp = tmp->to;
	}
}