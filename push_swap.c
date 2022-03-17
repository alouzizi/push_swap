/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:53:20 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/16 21:49:00 by alouzizi         ###   ########.fr       */
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
		sort(&stack_a, &stack_b, i);
	}
	else
		exit(1);
}
