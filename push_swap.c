/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:53:20 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/08 20:05:39 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*str;
	char	**s;
	char	*str2;
	int		i;
	int		j;

	if (ac >= 2)
	{
		str2 = (char *)malloc(sizeof(char));
		i = 1;
		while (i <= ac - 1)
		{
			str = ft_strjoin(str2, av[i]);
			free(str2);
			str2 = ft_strjoin(str, " ");
			free(str);
			i++;
		}
		i = 0;
		j = 0;
		while (str2[i++] == ' ')
			j++;
		if (j == (int)ft_strlen(str2))
			return (0);
		s = ft_split(str2, ' ');
		free(str2);
		if (ckeck_args(s) == 0)
			exit(1);
		i = 0;
		while (s[i])
		{
			push(&stack_a, ft_atoi(s[i++]));
			free(s[i]);
		}
		free(s);
		if (i < 3)
			sort2(&stack_a);
		if (i == 3)
			sort3(&stack_a);
		if (i > 3 && i < 6)
			sort5(&stack_a, &stack_b);
		if (i > 5)
			sort(&stack_a, &stack_b);
	}
	else
		exit(1);
}
