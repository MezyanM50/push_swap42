/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:29 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/15 17:03:22 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				is_after_middle;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				n;
	int				start;
	int				end;
	int				*array;
}					t_chunk;

long				ft_new_atoi(const char *str);
void				print_error(char *str);
int					free_tab(char **tab);
void				check_for_error(char **str);
t_stack				*create_new(int value, int index);
t_stack				*list_last(t_stack *lst);
void				add_back(t_stack **lst, t_stack *new);
void				add_front(t_stack **lst, t_stack *new);
int					list_size(t_stack *lst);
int					free_list(t_stack **lst);
void				print_stack(t_stack *lst);
char				**allocate_str(char **argv, int argc);
int					is_list_sorted(t_stack *lst);

void				sa(t_stack **lst, int is_print);
void				sb(t_stack **lst, int is_print);
void				ss(t_stack **lst_a, t_stack **lst_b);

void				push_any(t_stack **lst1, t_stack **lst2);
void				pa(t_stack **lst_a, t_stack **lst_b);
void				pb(t_stack **lst_a, t_stack **lst_b);

void				ra(t_stack **lst_a, int is_print);
void				rb(t_stack **lst_b, int is_print);
void				rr(t_stack **lst_b, t_stack **lst_a);

void				rra(t_stack **lst_a, int is_print);
void				rrb(t_stack **lst_b, int is_print);
void				rrr(t_stack **lst_a, t_stack **lst_b);

void				sort_algo(t_stack **lst_a, t_stack **lst_b);
void				long_sort(t_stack **lst_a, t_stack **lst_b);
int					get_max(t_stack *lst);
void				initiate_index(t_stack **lst_b);
void				selection_sort(t_chunk *chunk, int size);
int					get_range(int size);
void				fill_and_sort_arr(t_chunk *chunk, t_stack **lst_a);
void				initiate_index(t_stack **lst_b);
t_stack				*get_node_max(t_stack **lst_b);
void				go_back_to_a(t_stack **lst_a, t_stack **lst_b);
int					get_min(t_stack *lst);
void				sort_three(t_stack **lst_a);
void				sort_four_util(t_stack **lst_a, t_stack **lst_b);
void				sort_four(t_stack **lst_a, t_stack **lst_b);
void				sort_five_util(t_stack **lst_a, t_stack **lst_b);
void				sort_five(t_stack **lst_a, t_stack **lst_b);
void				sort_algo(t_stack **lst_a, t_stack **lst_b);

#endif