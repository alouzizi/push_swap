/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:42:52 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:25:38 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**s;
	char	*str2;
	int		i;

	if (ac >= 2)
	{
		join_arg(ac, av, &str2);
		s = ft_split(str2, ' ');
		if (ckeck_args(s, str2) == 1)
			exit(1);
		free(str2);
		i = 0;
		while (s[i])
		{
			push(&stack_a, ft_atoi(s[i]));
			free(s[i++]);
		}
		free(s);
		if (get_instructions(&stack_a, &stack_b) == 0)
			is_sorted(&stack_a);
	}
	else
		exit(1);
}

int	get_instructions(t_node **stack_a, t_node **stack_b)
{
	char	*r;

	r = get_next_line(0);
	while (r != NULL)
	{
		if (r == NULL)
			break ;
		else if (ft_strncmp(r, "sa", 2) == 0)
			swap(&*stack_a);
		else if (ft_strncmp(r, "sb", 2) == 0)
			swap(&*stack_b);
		else if (ft_strncmp(r, "ss", 2) == 0)
			double_rules(&*stack_a, &*stack_b, 1);
		else if (ft_strncmp(r, "rra", 3) == 0)
			reverse_rotate(&*stack_a);
		else if (ft_strncmp(r, "rrb", 3) == 0)
			reverse_rotate(&*stack_b);
		else if (ft_strncmp(r, "rrr", 3) == 0)
			double_rules(&*stack_a, &*stack_b, 3);
		else if (get_instructions2(&*stack_a, &*stack_b, &r) == 1)
			return (1);
		free(r);
		r = get_next_line(0);
	}
	return (0);
}

int	get_instructions2(t_node **stack_a, t_node **stack_b, char **r)
{
	if (ft_strncmp(*r, "ra", 2) == 0)
		rotate(&*stack_a);
	else if (ft_strncmp(*r, "rb", 2) == 0)
		rotate(&*stack_b);
	else if (ft_strncmp(*r, "rr", 2) == 0)
		double_rules(&*stack_a, &*stack_b, 2);
	else if (ft_strncmp(*r, "pa", 2) == 0)
		top_totop(&*stack_b, &*stack_a);
	else if (ft_strncmp(*r, "pb", 2) == 0)
		top_totop(&*stack_a, &*stack_b);
	else
	{
		write(2, "Erore\n", 6);
		free(*r);
		return (1);
	}
	return (0);
}

void	is_sorted(t_node **stack_a)
{
	t_node	*temp;
	int		i;

	temp = (*stack_a)->next;
	i = (*stack_a)->data;
	while (temp)
	{
		if (i > temp->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		i = temp->data;
		temp = temp->next;
	}
	write(1, "OK\n", 3);
	return ;
}
