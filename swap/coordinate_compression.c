# include "../list/double_list.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

size_t	ft_linearsort(int *array, size_t size)
{
	size_t	i;
	size_t 	j;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (i < j)
		{
			if (array[j] > array[j - 1])
				ft_swap(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
}

void	ft_ranking(order, array, size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (order[i] == array[j])
			{
				order[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	*coordnate(list *list, size_t size)
{
	size_t	i;
	int		*order;
	int		*array;
	node	*current;

	i = 0;
	order = malloc(sizeof(int) * (size + 1));
	array = malloc(sizeof(int) * (size + 1));
	order[size] = 0;
	array[size] = 0;
	current = list->head->to;
	while (current != list->head)
	{
		array[i] = order[i] = current->val;
		current = current->to;
		i++;
	}
	ft_linearsort(array, size);
	ft_ranking(order, array, size);
	free(array);
	return (&order);
}

// ・元の配列aを、別の配列valsにコピー
// ・valsをソート
// ・valsから重複した要素を消す。
// ・配列aをなめて二分探索でvalsからインデックスを取得