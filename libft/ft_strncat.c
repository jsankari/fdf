/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:43:04 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/30 13:05:40 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (s1[i])
		i++;
	while (s2[x] && n > 0)
	{
		s1[i] = s2[x];
		x++;
		i++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
