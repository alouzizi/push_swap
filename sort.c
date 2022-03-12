/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:52:50 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/12 15:10:57 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_node **top)
{
	if ((*top)->next == NULL)
		exit(2);
	if ((*top)->data > (*top)->next->data)
		swap(&*top, 'a');
	else
		exit(2);
}

void	sort3(t_node **top)
{
	if ((*top)->data < (*top)->next->data
		&& (*top)->next->data > (*top)->next->next->data)
	{
		if ((*top)->data < (*top)->next->next->data)
		{
			reverse_rotate(&*top, 'a');
			swap(&*top, 'a');
		}
		else
			reverse_rotate(&*top, 'a');
	}
	if ((*top)->data > (*top)->next->data
		&& (*top)->next->data < (*top)->next->next->data)
	{
		if ((*top)->data > (*top)->next->next->data)
			rotate(&*top, 'a');
		else
			swap(&*top, 'a');
	}
	if ((*top)->data > (*top)->next->data
		&& (*top)->data > (*top)->next->next->data)
	{
		swap(&*top, 'a');
		reverse_rotate(&*top, 'a');
	}
}

void	sort5(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (i == 4)
		min_push(&*stack_a, &*stack_b);
	min_push(&*stack_a, &*stack_b);
	sort3(&*stack_a);
	if (i == 4)
		top_totop(&*stack_b, &*stack_a, 'a');
	top_totop(&*stack_b, &*stack_a, 'a');
}

void	sort_all(t_node **a, t_node **b)
{
	int		*index;
	int		*s;
	int		*data;
	int		i;
	int		l;

	s = list_to_tab(&*a);
	i = lent(&*a);
	l = 0;
	index = long_subscoince(s, i, &l);
	data = get_subscoinc_data(index, l, s);
	l = sizeof(data) / sizeof(int);
	while (i-- > 0)
	{
		if (check_data((*a)->data, data, l) == 0)
			rotate(&*a, 'a');
		else if (check_data((*a)->data, data, l) == 1)
			top_totop(&*a, &*b, 'b');
	}
	while (*b)
		start_sorting(&*a, &*b);
	i = index_min(&*a);
	smart_push(&*a, &*b, i, 'a');
}
