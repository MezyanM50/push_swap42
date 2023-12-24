#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
}	t_stack;

# include <stdio.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"
#include <limits.h>

void error_hunter(int i, char **s);
void error_detect(char *s);
int is_number(char *str);
t_stack *listnew(int value, int index);
t_stack *lastlist(t_stack *list);
void list_addback(t_stack *new,t_stack **lst);
void list_addfront(t_stack *new,t_stack **list);
int listsize(t_stack *a);

#endif
