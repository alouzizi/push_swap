/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:49:16 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/16 21:48:53 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b, int i)
{
	if (i < 3)
		sort2(&*a);
	if (i == 3)
		sort3(&*a);
	if (i > 3 && i < 6)
		sort5(&*a, &*b);
	if (i > 5)
		sort_all(&*a, &*b);
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
