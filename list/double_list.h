#ifndef DOUBLE_LIST_H
# define DOUBLE_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int         val;
    struct Node *to;
    struct Node *from;
}	node;

typedef struct List
{
	node	*head;
}	list;


void	lst_init(list *list);
void	lst_pushback(list *list, int n);
size_t	lst_size(list *stack_A);
void	lst_print(list *list);
void	lst_free(list *lsit);

#endif
