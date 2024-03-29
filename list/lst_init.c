/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:48:53 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:48:54 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*lst_init(void)
{
	t_list	*list;
	t_node	*head_a;
	t_node	*head_b;

	list = (t_list *)malloc(sizeof(t_list));
	head_a = (t_node *)malloc(sizeof(t_node));
	head_b = (t_node *)malloc(sizeof(t_node));
	head_a->from = head_a;
	head_a->to = head_a;
	list->head_a = head_a;
	head_b->from = head_b;
	head_b->to = head_b;
	list->head_b = head_b;
	return (list);
}

// head -> head
//		<- head
//  ^
//  |
// list