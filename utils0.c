/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:41:06 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/08 20:40:07 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lent(t_node **head)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	index_max(t_node **stack)
{
	t_node	*temp;
	t_node	*temp1;
	int		n;
	int		i;

	temp = *stack;
	temp1 = (*stack)->next;
	n = temp->data;
	while (temp1)
	{
		if (n < temp1->data)
			n = temp1->data;
		temp1 = temp1->next;
	}
	i = 0;
	while (temp->next)
	{
		if (temp->data == n)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	index_min(t_node **stack)
{
	t_node	*temp;
	t_node	*temp1;
	int		n;
	int		i;

	temp = *stack;
	temp1 = (*stack)->next;
	n = temp->data;
	while (temp1)
	{
		if (n > temp1->data)
			n = temp1->data;
		temp1 = temp1->next;
	}
	i = 0;
	while (temp->next)
	{
		if (temp->data == n)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

void	min_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	int		i;
	int		j;

	i = 0;
	temp = *stack_a;
	j = index_min(&*stack_a);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (i / 2 >= j)
	{
		while (j--)
			rotate(&*stack_a, 'a');
	}
	else if (i / 2 < j)
	{
		j = i - j;
		j++;
		while (j--)
			reverse_rotate(&*stack_a, 'a');
	}
	top_totop(&*stack_a, &*stack_b, 'b');
}

void	smart_push(t_node **a, t_node **b, int index, char c)
{
	t_node	*temp;
	int		i;
	int		j;

	i = 0;
	if (c == 'a')
		temp = *a;
	if (c == 'b')
		temp = *b;
	j = index;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (i / 2 >= j)
	{
		while (j)
		{
			if (c == 'a')
				rotate(&*a, 'a');
			else if (c == 'b')
				rotate(&*b, 'b');
			j--;
		}
	}
	else if (i / 2 < j)
	{
		j = i - j + 1;
		while (j > 0)
		{	
			if (c == 'a')
				reverse_rotate(&*a, 'a');
			if (c == 'b')
				reverse_rotate(&*b, 'b');
			j--;
		}
	}
	if (c == 'b')
		top_totop(&*b, &*a, 'a');
	return ;
}
