/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:49:16 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:36:16 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_instructions(t_node	**a, t_node **b, int d, int data)
{
	while ((*b)->data != data && (*a)->data != d)
		double_rules(&*a, &*b, 3);
	while ((*a)->data != d)
		reverse_rotate(&*a, 'a');
	while ((*b)->data != data)
		reverse_rotate(&*b, 'b');
}

void	long_subscoince_2(int *arr, int n, int **prev, int **lis)
{
	int	i;
	int	j;
	int	p;

	i = 1;
	p = 1;
	(*lis)[0] = 1;
	while (i < n)
	{
		(*lis)[i] = 1;
		j = 0;
		while (j++ < i)
		{
			if (arr[i] > arr[j] && (*lis)[i] <= (*lis)[j] + 1)
			{
				(*lis)[i] = (*lis)[j] + 1;
				(*prev)[p] = j;
			}
		}
		p++;
		i++;
	}	
}

int	is_sorted(t_node **stack_a)
{
	t_node	*temp;
	int		i;

	temp = (*stack_a)->next;
	i = (*stack_a)->data;
	while (temp)
	{
		if (i > temp->data)
			return (1);
		i = temp->data;
		temp = temp->next;
	}
	return (0);
}
