/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:42:52 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 09:31:19 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**s;
	char	*str2;
	int		i;
	char	*r;

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
		i = 1;
		while (i != 0)
		{
			i = read(0, str2, 1);
			while(1);
			if (i == -1)
			{
				free(str2);
				write(2, "Erore\n", 6);
				exit(1);
			}
			str2[i] = '\0';
			r = ft_strjoin(r, str2);
		}
		free(str2);
		printf("%s", r);
		// while (get_next_line(0) != NULL)
		// {
		// 	r = get_next_line(0);
		// 	if (ft_strncmp(r, "sa", 2) == 0)
		// 	{
		// 		printf("ko\n");
		// 		swap(&stack_a, '0');
		// 	}
		// 	else if (ft_strncmp(r, "sb", 2))
		// 		swap(&stack_b, '0');
		// 	else if (ft_strncmp(r, "ss", 2))
		// 		double_rules(&stack_a, &stack_b, 1);
		// 	else if (ft_strncmp(r, "ra", 2))
		// 		rotate(&stack_a, '0');
		// 	else if (ft_strncmp(r, "rb", 2))
		// 		rotate(&stack_b, '0');
		// 	else if (ft_strncmp(r, "rr", 2))
		// 		double_rules(&stack_a, &stack_b, 2);
		// 	else if (ft_strncmp(r, "rra", 3))
		// 		reverse_rotate(&stack_a, '0');
		// 	else if (ft_strncmp(r, "rrb", 3))
		// 		reverse_rotate(&stack_b, '0');
		// 	else if (ft_strncmp(r, "rrr", 3))
		// 		double_rules(&stack_a, &stack_b, 3);
		// 	else if (ft_strncmp(r, "pa\n", 3))
		// 		top_totop(&stack_b, &stack_a, '0');
		// 	else if (ft_strncmp(r, "pb\n", 3))
		// 		top_totop(&stack_a, &stack_b, '0');
		// 	else
		// 		write(2, "ERORE\n", 6);
		// }
		while (stack_a)
		{
			printf("[%d]\n", stack_a->data);
			stack_a = stack_a->next;
		}
		while (stack_b)
		{
			printf("{%d}\n", stack_b->data);
			stack_b = stack_b->next;
		}
	}
	else
		exit(1);
}

void	is_sorted(t_node **stack_a)
{
	t_node	*temp;
	int		i;

	temp = *stack_a;
	i = temp->data;
	temp = temp->next;
	while (temp)
	{
		if (i > temp->data)
		{
			write(2, "Erore\n", 6);
			return ;
		}
		i = temp->data;
		temp = temp->next;
	}
	return ;
}
