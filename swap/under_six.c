/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:48:39 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:54:09 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	opposite_char(char which)
{
	if (which == 'a')
		return ('b');
	else if (which == 'b')
		return ('a');
	return ('r');
}

void	move_smlval(t_list *stack, t_node *head, size_t num, char which)
{
	size_t	cnt;
	size_t	size;
	t_node	*tmp;

	cnt = 0;
	size = lst_size(head);
	tmp = head->to;
	while (tmp->val != num)
	{
		tmp = tmp->to;
		cnt++;
	}
	if (cnt <= size / 2)
	{
		while (head->to->val != num)
		{
			if (head->to->to->val == num)
				command_s(stack, which);
			else
				command_r(stack, which);
		}
	}
	else
		while (head->to->val != num)
			command_rr(stack, which);
	command_p(stack, which);
}

void	under_six(t_list *stack, t_node *head, size_t size, char which)
{
	size_t	i;
	t_node	*tmp;

	i = 1;
	while (i <= size - 3)
	{
		tmp = head->to;
		while (tmp != head)
		{
			if (tmp->val == i)
			{
				move_smlval(stack, head, i, which);
				break ;
			}
			if (tmp->to->val == size - 3 && already_swapped(head) == 1)
				break ;
			tmp = tmp->to;
		}
		i++;
	}
	if (!already_swapped(head))
		under_three(stack, head, 3, which);
	while (i-- > 1)
		command_p(stack, opposite_char(which));
}

// push the numbers up to size-3 from the smaller one of stack_A to stack_B in order
// Then arrange the numbers in stack_A in ascending order
// Then push the numbers in stack_B to stack_A