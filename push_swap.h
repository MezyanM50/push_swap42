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

//operations
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a,t_stack **b);
void pa(t_stack **a,t_stack **b);
void pb(t_stack **a,t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **b, t_stack **a);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a,t_stack **b);

//check
int isn_sorted(t_stack *lst);

//utils
int get_max(t_stack *a);
#endif
