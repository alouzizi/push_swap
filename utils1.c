/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:01:20 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/08 20:36:30 by alouzizi         ###   ########.fr       */
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
	return (j);
}

int	*long_subscoince(int *arr, int n, int *l)
{
	int	*lis;
	int	*prev;
	int	i;
	int	j;
	int	p;

	i = 1;
	p = 1;
	lis = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	lis[0] = 1;
	while (i < n)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] <= lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[p] = j;
			}
			j++;
		}
		p++;
		i++;
	}
	j = 1;
	i = lis[0];
	while (j < n)
	{
		if (i < lis[j])
		{
			i = lis[j];
			prev[0] = j;
		}
		j++;
	}
	*l = i;
	return (prev);
}
