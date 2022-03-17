/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:49:36 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/17 21:35:53 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_node **a, t_node **b, int i)
{
	if (is_sorted(&*a) == 0)
		return ;
	if (i < 3)
		sort2(&*a);
	if (i == 3)
		sort3(&*a);
	if (i > 3 && i < 6)
		sort5(&*a, &*b);
	if (i > 5)
		sort_all(&*a, &*b);
}

int	*list_to_tab(t_node **list)
{
	t_node	*temp;
	int		*s;
	int		i;

	i = 0;
	s = malloc(sizeof(int) * lent(&*list));
	temp = *list;
	while (temp)
	{
		s[i++] = temp->data;
		temp = temp->next;
	}
	return (s);
}

void	get_subscoinc_data(int *index, int l, int *s, int **data)
{
	int	k;
	int	n;
	int	i;
	int	t;

	(*data) = malloc(sizeof(int) * l);
	k = l;
	i = index[0];
	n = 0;
	t = index[0];
	while (k-- > 0)
	{
		(*data)[n] = s[t];
		t = index[i];
		i = index[i];
		n++;
	}
	free(index);
	free(s);
}
