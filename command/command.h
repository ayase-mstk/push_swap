#ifndef COMMAND_H
# define COMMAND_H

# include "../list/double_list.h"

void	sa_command(list *stack_A);
void	sb_command(list *stack_B);
void	ss_command(list *stack_A, list *stack_B);
void	ra_command(list *stack_A);
void	rb_command(list *stack_B);
void	rr_command(list *stack_A, list *stack_B);
void	rra_command(list *stack_A);
void	rrb_command(list *stack_A);
void	rrr_command(list *stack_A, list *stack_B);
void	pa_command(list *stack_A, list *stack_B);
void	pb_command(list *stack_A, list *stack_B);

#endif