/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:03:55 by alouzizi          #+#    #+#             */
/*   Updated: 2022/02/23 19:03:12 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	while (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (len + 1));
	while (!s)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		s[j++] = s2[i++];
	}
	s[j] = '\0';
	return (s);
}
