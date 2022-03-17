/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:24:11 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:23:56 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
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
void	swap(t_node **head);
void	rotate(t_node **head);
void	reverse_rotate(t_node **head);
void	top_totop(t_node **top, t_node **stack);
void	double_rules(t_node **stack_a, t_node **stack_b, int s);
void	push(t_node **head, int data);
int		check1(char **s);
int		check2(char **s);
int		ckeck_args(char **s, char *str);
int		to_top(t_node **stack, int index);
void	join_arg(int ac, char **av, char **str2);
void	is_sorted(t_node **stack_a);
int		get_instructions(t_node **stack_a, t_node **stack_b);
int		get_instructions2(t_node **stack_a, t_node **stack_b, char **r);
#endif