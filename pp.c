/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:49:36 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/07 16:55:40 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_node *head)
{
	if (head == NULL)
	{
		printf("stack Underflow");
		exit (1);
	}
	return (head->data);
}

void	push(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*temp;

	temp = *head;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{	
		printf("stack overflow");
		return ;
	}
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
		(*head) = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

int	pop(t_node **head)
{
	t_node	*temp;
	t_node	*last;
	int		data;

	if (head == NULL)
	{
		printf("stack Underflow");
		exit (1);
	}
	temp = *head;
	last = *head;
	while (last->next)
		last = last->next;
	data = last->data;
	free(last);
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	free (temp);
	temp = NULL;
	return (data);
}