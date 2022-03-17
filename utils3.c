/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:37:24 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 17:17:02 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	real_sorting(t_node **a, t_node **b, int best, int index)
{
	int	j;
	int	d;
	int	data;

	data = get_data_by_index(index, &*b);
	j = position(data, &*a);
	d = get_data_by_index(j, &*a);
	if (best == 0)
	{
		smart_push(&*a, &*b, j, 'a');
		smart_push(&*b, &*a, index, 'b');
		return ;
	}
	if (best == 1)
	{
		while ((*b)->data != data && (*a)->data != d)
			double_rules(&*a, &*b, 2);
		while ((*a)->data != d)
			rotate(&*a, 'a');
		while ((*b)->data != data)
			rotate(&*b, 'b');
	}
	if (best == 2)
		min_instructions(&*a, &*b, d, data);
	top_totop(&*b, &*a, 'a');
}

int	get_data_by_index(int index, t_node **stack)
{
	t_node	*temp;
	int		j;

	j = 0;
	temp = *stack;
	while (temp)
	{
		if (j == index || index == 0)
		{
			break ;
		}
		j++;
		temp = temp->next;
	}
	return (temp->data);
}

int	min(t_node **stack)
{
	t_node	*temp;
	t_node	*temp1;
	int		n;

	temp = *stack;
	temp1 = (*stack)->next;
	n = temp->data;
	while (temp1)
	{
		if (n > temp1->data)
			n = temp1->data;
		temp1 = temp1->next;
	}
	return (n);
}

int	max(t_node **stack)
{
	t_node	*temp;
	t_node	*temp1;
	int		n;

	temp = *stack;
	temp1 = (*stack)->next;
	n = temp->data;
	while (temp1)
	{
		if (n < temp1->data)
			n = temp1->data;
		temp1 = temp1->next;
	}
	return (n);
}

int	max_index(int *s, int l)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	j = s[i];
	while (i < l)
	{
		if (j < s[i])
		{
			j = s[i];
			a = i;
		}
		i++;
	}
	return (a);
}
