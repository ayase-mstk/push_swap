/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:46:20 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 12:35:37 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	recursive_quick_sort_under20(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	tmp;

	tmp = high;
	while ((high--) - low + 1 > 3)
		move_smlval(stack, stack->head_b, high + 1, 'b');
	ft_pushswap(stack, stack->head_b, 'b');
	i = 0;
	while (i <= high - low + 1)
	{
		pa_command(stack);
		ra_command(stack);
		i++;
	}
	high = tmp;
	while ((high--) - low + 1 > 3)
		ra_command(stack);
}

size_t	recursive_quick_sort_else(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	pivot;

	i = high;
	pivot = (low + high) / 2;
	while (i > pivot)
	{
		if (stack->head_b->to->val > pivot)
		{
			pa_command(stack);
			i--;
		}
		else
			rb_command(stack);
	}
	return (i);
}

void	recursive_quick_sort(t_list *stack, size_t low, size_t high)
{
	size_t	i;
	size_t	pivot;

	pivot = (low + high) / 2;
	if (high - low + 1 <= 20)
	{
		recursive_quick_sort_under20(stack, low, high);
		return ;
	}
	else
	{
		i = recursive_quick_sort_else(stack, low, high);
		recursive_quick_sort(stack, low, pivot);
		while (i++ < high)
			pb_command(stack);
		recursive_quick_sort(stack, pivot + 1, high);
	}
}

void	send_ascending_order(t_list *stack, size_t pivot)
{
	size_t cnt;
	t_node *tmp;

	cnt = 0;
	while (cnt < pivot)
	{
		tmp = stack->head_a->to;
		if (tmp->val <= pivot)
		{
			pb_command(stack);
			cnt++;
		}
		else if (tmp->to->val == cnt + 1 && tmp->val == cnt + 2)
		{
			sa_command(stack);
			pb_command(stack);
			cnt++;
		}
		else
			ra_command(stack);
	}
}

void	over_seven(t_list *stack, size_t size)
{
	size_t	cnt;
	size_t	pivot;
	size_t	low;
	size_t	high;

	low = 1;
	high = size;
	pivot = (high + low) / 2;
	send_ascending_order(stack, pivot);
	recursive_quick_sort(stack, low, pivot);
	cnt = pivot;
	while (cnt++ < high)
		pb_command(stack);
	recursive_quick_sort(stack, pivot + 1, high);
}

// void	recursive_quick_sort(t_list *stack, size_t low, size_t high)
// {
// 	size_t	i;
// 	size_t	pivot;

// 	pivot = (low + high) / 2;
// 	if (high - low + 1 <= 20)
// 	{
// 		recursive_quick_sort_under20(stack, low, high);
// 		// pivot = high;
// 		// while ((high--) - low + 1 > 3)
// 		// 	move_smlval(stack, stack->head_b, high + 1, 'b');
// 		// ft_pushswap(stack, stack->head_b, 'b');
// 		// i = 0;
// 		// while (i <= high - low + 1)
// 		// {
// 		// 	pa_command(stack);
// 		// 	ra_command(stack);
// 		// 	i++;
// 		// }
// 		// high = pivot;
// 		// while ((high--) - low + 1 > 3)
// 		// 	ra_command(stack);
// 		return ;
// 	}
// 	else
// 	{
// 		i = recursive_quick_sort_else(stack, low, high);
// 		// i = high;
// 		// while (i > pivot)
// 		// {
// 		// 	if (stack->head_b->to->val > pivot)
// 		// 	{
// 		// 		pa_command(stack);
// 		// 		i--;
// 		// 	}
// 		// 	else
// 		// 		rb_command(stack);
// 		// }
// 		recursive_quick_sort(stack, low, pivot);
// 		while (i++ < high)
// 			pb_command(stack);
// 		recursive_quick_sort(stack, pivot + 1, high);
// 	}
// }
