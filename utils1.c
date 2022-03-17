/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:01:20 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:17:20 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	map(t_node **stack, int index, char str)
{
	int	i;
	int	j;

	if (str == 'h')
		return (index);
	else
	{
		i = lent(&*stack);
		j = i - index ;
		return (j);
	}
}

int	position(int data, t_node **stack_a)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*last;
	int		i;

	last = *stack_a;
	while (last->next)
		last = last->next;
	i = 1;
	temp1 = *stack_a;
	temp2 = (*stack_a)->next;
	while (temp2)
	{
		if (temp1->data < data && temp2->data > data)
			return (i);
		i++;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (data > max(&*stack_a))
		return (index_min(&*stack_a));
	else if (data < min(&*stack_a))
		return (index_min(&*stack_a));
	else
		return (0);
}

int	the_big(int *s, int l)
{
	int	i;
	int	j;

	i = 0;
	j = s[i];
	while (i < l)
	{
		if (j < s[i])
		{
			j = s[i];
		}
		i++;
	}
	return (j);
}

int	the_min(int *s, int l)
{
	int	i;
	int	j;

	i = 0;
	j = s[i];
	while (i < l)
	{
		if (j > s[i])
			j = s[i];
		i++;
	}
	free(s);
	return (j);
}

int	*long_subscoince(int *arr, int n, int *l)
{
	int	*lis;
	int	*prev;

	lis = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	long_subscoince_2(arr, n, &prev, &lis);
	prev[0] = max_index(lis, n);
	*l = the_big(lis, n);
	free(lis);
	return (prev);
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
	return (0) ;
}
