#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct Node
{
	int			val;
	struct Node	*to;
	struct Node	*from;
}	t_node;

typedef struct List
{
	t_node	*head;
}	t_list;

// list
void	lst_init(t_list *list);
void	lst_pushback(t_list *list, int n);
size_t	lst_size(t_list *stack_A);
void	lst_print(t_list *list);
void	lst_free(t_list *lsit);

// command
void	sa_command(t_list *stack_A);
void	sb_command(t_list *stack_B);
void	ss_command(t_list *stack_A, t_list *stack_B);
void	ra_command(t_list *stack_A);
void	rb_command(t_list *stack_B);
void	rr_command(t_list *stack_A, t_list *stack_B);
void	rra_command(t_list *stack_A);
void	rrb_command(t_list *stack_A);
void	rrr_command(t_list *stack_A, t_list *stack_B);
void	pa_command(t_list *stack_A, t_list *stack_B);
void	pb_command(t_list *stack_A, t_list *stack_B);

// pushswap
void	under_three(t_list *stack_A, size_t size);

// utils
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		*coordinate(int ac, char **av);

// main
int		main(int ac, char **av);
void	ft_pushswap(t_list *stack_A);

#endif
