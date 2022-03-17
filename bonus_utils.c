/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:10:34 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:10:39 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	join_arg(int ac, char **av, char **str2)
{
	int		i;
	char	*str;

	i = 1;
	(*str2) = (char *)malloc(sizeof(char));
	while (i <= ac - 1)
	{
		str = ft_strjoin((*str2), av[i++]);
		free((*str2));
		(*str2) = ft_strjoin(str, " ");
		free(str);
	}
	return ;
}
