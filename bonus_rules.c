/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:21:41 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:29:06 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node **head)
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
}

void	rotate(t_node **head)
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
}

void	reverse_rotate(t_node **head)
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
}

void	top_totop(t_node **stack_a, t_node **stack_b)
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
}

void	double_rules(t_node **stack_a, t_node **stack_b, int s)
{
	if (s == 1)
	{
		swap(&*stack_a);
		swap(&*stack_b);
	}
	if (s == 2)
	{
		rotate(&*stack_a);
		rotate(&*stack_b);
	}
	if (s == 3)
	{
		reverse_rotate(&*stack_a);
		reverse_rotate(&*stack_b);
	}
}
