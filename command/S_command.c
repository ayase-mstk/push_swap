/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   S_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:49:16 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:49:17 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_command(t_list *stack_A)
{
	t_node	*first;
	t_node	*second;

	first = stack_A->head_a->to;
	second = stack_A->head_a->to->to;
	second->from = stack_A->head_a;
	first->to = second->to;
	second->to = first;
	first->from = second;
	first->to->from = first;
	stack_A->head_a->to = second;
	ft_printf("sa\n");
}

void	sb_command(t_list *stack_B)
{
	t_node	*first;
	t_node	*second;

	first = stack_B->head_b->to;
	second = stack_B->head_b->to->to;
	second->from = stack_B->head_b;
	first->to = second->to;
	second->to = first;
	first->from = second;
	first->to->from = first;
	stack_B->head_b->to = second;
	ft_printf("sb\n");
}

void	ss_command(t_list *stack_A, t_list *stack_B)
{
	sa_command(stack_A);
	sb_command(stack_B);
	ft_printf("ss\n");
}

void	command_s(t_list *stack, char which)
{
	if (which == 'a')
		sa_command(stack);
	else if (which == 'b')
		sb_command(stack);
	else if (which == 's')
		ss_command(stack, stack);
}
