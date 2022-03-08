/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:14:58 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/08 20:32:53 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_data(int data, int *s, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (s[i] == data)
			return (0);
		i++;
	}
	return (1);
}

void	start_sorting(t_node **a, t_node **b)
{
	t_node	*tb;
	int		*moves;
	int		i;
	int		j;
	int		d;

	tb = *b;
	i = 0;
	d = 0;
	moves = malloc(sizeof(int) * lent(&*b));
	while (tb)
	{
		j = position(tb->data, &*a);
		moves[d++] = the_min(a9al_moves(&*a, &*b, j, i), 3);
		i++;
		tb = tb->next;
	}
	j = min_index(moves, lent(*&b));
	d = get_data_by_index(j, &*b);
	i = position(d, &*a);
	d = min_index(a9al_moves(&*a, &*b, i, j), 3);
	real_sorting(&*a, &*b, d, j);
}

int	*a9al_moves(t_node **a, t_node **b, int ia, int ib)
{
	int	*s;

	s = malloc(sizeof(int) * 3);
	s[0] = (to_top(&*a, ia) + to_top(&*b, ib));
	if (map(&*a, ia, 'h') > map(&*b, ib, 'h'))
		s[1] = map(&*a, ia, 'h');
	else
		s[1] = map(&*b, ib, 'h');
	if (map(&*a, ia, 'b') > map(&*b, ib, 'b'))
		s[2] = map(&*a, ia, 'b');
	else
	s[2] = map(&*b, ib, 'b');
	return (s);
}

int	to_top(t_node **stack, int index)
{
	t_node	*temp;
	int		j;
	int		i;

	i = 0;
	j = index;
	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (i / 2 >= j)
		return (j);
	else
	{
		j = i - j + 1;
		return (j);
	}	
}

int	min_index(int *s, int l)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	j = s[i];
	while (i < l)
	{
		if (j > s[i])
		{
			j = s[i];
			a = i;
		}
		i++;
	}
	return (a);
}
