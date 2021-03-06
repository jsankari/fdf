/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:54:36 by jsankari          #+#    #+#             */
/*   Updated: 2020/07/03 13:18:55 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1p;
	unsigned const char	*s2p;

	s1p = s1;
	s2p = s2;
	while (n)
	{
		if (*s1p != *s2p)
		{
			return (*s1p - *s2p);
		}
		s1p++;
		s2p++;
		n--;
	}
	return (0);
}
