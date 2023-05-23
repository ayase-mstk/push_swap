#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_linearsort(int *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (i < j)
		{
			if (array[j] < array[j - 1])
				ft_swap(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
}

void	ft_ranking(int *rank, int *order, int *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (order[i] == array[j])
			{
				rank[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	*coordinate(char **av, int size)
{
	int		i;
	int		j;
	int		*order;
	int		*array;
	int		*rank;

	i = 0;
	j = 0;
	order = malloc(sizeof(int) * size);
	array = malloc(sizeof(int) * size);
	rank = malloc(sizeof(int) * size);
	order[size - 1] = 0;
	array[size - 1] = 0;
	rank[size - 1] = 0;
	while (i < size)
	{
		array[j] = ft_atoi(av[i]);
		order[j] = array[j];
		i++;
		j++;
	}
	ft_linearsort(array, size);
	ft_ranking(rank, order, array, size);
	free(array);
	free(order);
	return (rank);
}

// ・元の配列aを、別の配列valsにコピー
// ・valsをソート
// ・valsから重複した要素を消す。
// ・配列aをなめて二分探索でvalsからインデックスを取得