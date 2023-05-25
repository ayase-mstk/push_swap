/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   R_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:49:09 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:49:10 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_command(t_list *stack_A)
{
	stack_A->head_a->to->from = stack_A->head_a->from;
	stack_A->head_a->from->to = stack_A->head_a->to;
	stack_A->head_a->to = stack_A->head_a->to->to;
	stack_A->head_a->from->to->to = stack_A->head_a;
	stack_A->head_a->from = stack_A->head_a->from->to;
	ft_printf("ra\n");
}

void	rb_command(t_list *stack_B)
{
	stack_B->head_b->to->from = stack_B->head_b->from;
	stack_B->head_b->from->to = stack_B->head_b->to;
	stack_B->head_b->to = stack_B->head_b->to->to;
	stack_B->head_b->from->to->to = stack_B->head_b;
	stack_B->head_b->from = stack_B->head_b->from->to;
	ft_printf("rb\n");
}

void	rr_command(t_list *stack_A, t_list *stack_B)
{
	ra_command(stack_A);
	rb_command(stack_B);
	ft_printf("rr\n");
}

void	command_r(t_list *stack, char which)
{
	if (which == 'a')
		ra_command(stack);
	else if (which == 'b')
		rb_command(stack);
	else if (which == 'r')
		rr_command(stack, stack);
}
