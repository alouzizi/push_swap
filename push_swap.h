/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:29:00 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/16 21:49:01 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <string.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define INT_MIN  -2147483648
# define INT_MAX  2147483647

typedef struct node{
	int			data;
	struct node	*next;
}t_node;

int		check_args(char *s);
void	swap(t_node **head, char c);
void	rotate(t_node **head, char c);
void	reverse_rotate(t_node **head, char c);
int		pop(t_node **head);
void	push(t_node **head, int data);
int		check1(char **s);
int		check2(char **s);
int		ckeck_args(char **s, char *str);
void	top_totop(t_node **top, t_node **stack, char c);
void	double_rules(t_node **stack_a, t_node **stack_b, int s);
void	sort3(t_node **top);
void	sort2(t_node **top);
void	sort5(t_node **stack_a, t_node **stack_b);
void	sort_all(t_node **stack_a, t_node **stack_b);
int		index_min(t_node **stack);
void	min_push(t_node **stack_a, t_node **stack_b);
int		index_max(t_node **stack);
int		lent(t_node **head);
int		position(int data, t_node **stack_a);
int		map(t_node **stack, int index, char str);
void	smart_push(t_node **a, t_node **b, int index, char c);
int		the_big(int *s, int l);	
int		the_min(int *s, int l);
int		*long_subscoince(int *arr, int n, int *l);
int		check_data(int data, int *s, int l);
int		*a9al_moves(t_node **a, t_node **b, int ia, int ib);
int		to_top(t_node **stack, int index);
void	start_sorting(t_node **a, t_node **b);
int		min_index(int *s, int l);
int		get_data_by_index(int index, t_node **stack);
void	real_sorting(t_node **a, t_node **b, int best, int index);
int		min(t_node **stack);
int		max(t_node **stack);
void	sort(t_node **a, t_node **b, int i);
int		max_index(int *s, int l);
void	get_subscoinc_data(int *index, int l, int *s, int **data);
int		*list_to_tab(t_node **list);
void	min_instructions(t_node	**a, t_node **b, int d, int data);
void	join_arg(int ac, char **av, char **str2);
void	long_subscoince_2(int *arr, int n, int **prev, int **lis);
void	is_sorted(t_node **stack_a);
#endif
