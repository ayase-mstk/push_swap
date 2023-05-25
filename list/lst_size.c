/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:49:01 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:49:02 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	lst_size(t_node *head)
{
	size_t	size;
	t_node	*p;

	size = 0;
	p = head->to;
	while (p != head)
	{
		size++;
		p = p->to;
	}
	return (size);
}
