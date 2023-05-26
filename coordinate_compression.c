/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:46:26 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/26 21:58:44 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	*coordinate(char **allav, size_t size)
{
	size_t		i;
	int		*order;
	int		*array;
	int		*rank;

	i = 0;
	order = malloc(sizeof(int) * size);
	array = malloc(sizeof(int) * size);
	rank = malloc(sizeof(int) * size);
	order[size - 1] = 0;
	array[size - 1] = 0;
	rank[size - 1] = 0;
	while (i < size)
	{
		array[i] = ft_atoi(allav[i]);
		order[i] = array[i];
		i++;
	}
	ft_linearsort(array, size);
	ft_ranking(rank, order, array, size);
	// free_allav(allav, size);
	free(order);
	free(array);
	return (rank);
}

// ・copy array a to another array vals
// ・sort vals
// ・delete duplicate elements from vals
// ・search array a to get index from vals by binary search