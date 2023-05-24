#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
#include "./libftprintf/ft_printf.h"
#include "./libft/libft.h"

typedef struct Node
{
	size_t		val;
	struct Node	*to;
	struct Node	*from;
}	t_node;

typedef struct List
{
	t_node	*head_a;
	t_node	*head_b;
}	t_list;

// list
t_list	*lst_init(void);
void	lst_pushback(t_list *list, int n);
size_t	lst_size(t_node *head);
void	lst_print(t_list *list);
void	lst_free(t_list *lsit);

// command
void	ra_command(t_list *stack_A);
void	rb_command(t_list *stack_B);
void	rr_command(t_list *stack_A, t_list *stack_B);
void	rra_command(t_list *stack_A);
void	rrb_command(t_list *stack_A);
void	rrr_command(t_list *stack_A, t_list *stack_B);
void	pa_command(t_list *stack);
void	pb_command(t_list *stack);
void	sa_command(t_list *stack_A);
void	sb_command(t_list *stack_B);
void	ss_command(t_list *stack_A, t_list *stack_B);
void	command_r(t_list *stack, char which);
void	command_rr(t_list *stack, char which);
void	command_p(t_list *stack, char which);
void	command_s(t_list *stack, char which);

// pushswap
void	under_three(t_list *stack, t_node *head, size_t size, char which);
void	swap_three(t_list *stack, t_node *head, char which);
void	under_six(t_list *stack, t_node *head, size_t size, char which);
void	over_seven(t_list *stack, size_t size);

// main
int		main(int ac, char **av);
void	ft_pushswap(t_list *stack_A);
int		already_swapped(t_node *head);
int		*coordinate(char **av, int size);
int		error(char **av);

#endif
