/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:25:41 by alouzizi          #+#    #+#             */
/*   Updated: 2022/03/15 10:51:46 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check1(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		if (ft_atoi(s[i]) > INT_MAX || ft_atoi(s[i]) < INT_MIN)
			return (1);
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check2(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '+' || s[i][j] == '-')
				j++;
			if (s[i][j] == '\0')
				return (1);
			while (s[i][j])
			{
				if (!ft_isdigit(s[i][j]))
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ckeck_args(char **s, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i++] == ' ')
		j++;
	if (j == (int)ft_strlen(str))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (check1(s) == 0 && check2(s) == 0)
		return (0);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
