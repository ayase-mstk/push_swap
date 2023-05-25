/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:48:55 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:48:56 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_print(t_list *list)
{
	t_node	*a_ptr;
	t_node	*b_ptr;

	a_ptr = list->head_a->to;
	b_ptr = list->head_b->to;
	ft_printf("a\tb\n");
	ft_printf("----------\n");
	while (a_ptr != list->head_a || b_ptr != list->head_b)
	{
		if (a_ptr != list->head_a)
		{
			ft_printf("%d", a_ptr->val);
			a_ptr = a_ptr->to;
		}
		ft_printf("\t");
		if (b_ptr != list->head_b)
		{
			ft_printf("%d", b_ptr->val);
			b_ptr = b_ptr->to;
		}
		ft_printf("\n");
	}
}
