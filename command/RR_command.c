/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RR_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:45:41 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:45:42 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_command(t_list *stack_A)
{
	t_node	*first;
	t_node	*last;

	first = stack_A->head_a->to;
	last = stack_A->head_a->from;
	last->to = first;
	first->from = last;
	stack_A->head_a->from = last->from;
	last->from->to = stack_A->head_a;
	stack_A->head_a->to = last;
	last->from = stack_A->head_a;
	ft_printf("rra\n");
}

void	rrb_command(t_list *stack_B)
{
	t_node	*first;
	t_node	*last;

	first = stack_B->head_b->to;
	last = stack_B->head_b->from;
	last->to = first;
	first->from = last;
	stack_B->head_b->from = last->from;
	last->from->to = stack_B->head_b;
	stack_B->head_b->to = last;
	last->from = stack_B->head_b;
	ft_printf("rrb\n");
}

void	rrr_command(t_list *stack_A, t_list *stack_B)
{
	rra_command(stack_A);
	rrb_command(stack_B);
	ft_printf("rrr\n");
}

void	command_rr(t_list *stack, char which)
{
	if (which == 'a')
		rra_command(stack);
	else if (which == 'b')
		rrb_command(stack);
	else if (which == 'r')
		rrr_command(stack, stack);
}
