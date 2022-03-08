/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:27:36 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/08 18:28:48 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head, char c)
{
	t_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_node **head, char c)
{
	t_node	*temp;
	t_node	*temp2;

	temp2 = *head;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	*head = (*head)->next;
	temp->next = temp2;
	temp2->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_node **head, char c)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = *head;
	temp2 = *head;
	while (temp1->next)
		temp1 = temp1->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = *head;
	*head = temp1;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	top_totop(t_node **stack_a, t_node **stack_b, char c)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_b;
		*stack_b = temp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	double_rules(t_node **stack_a, t_node **stack_b, int s)
{
	if (s == 1)
	{
		swap(&*stack_a, '0');
		swap(&*stack_b, '0');
		write(1, "ss\n", 3);
	}
	if (s == 2)
	{
		rotate(&*stack_a, '0');
		rotate(&*stack_b, '0');
		write(1, "rr\n", 3);
	}
	if (s == 3)
	{
		reverse_rotate(&*stack_a, '0');
		reverse_rotate(&*stack_b, '0');
		write(1, "rrr\n", 4);
	}
}
