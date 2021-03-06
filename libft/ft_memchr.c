/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:00:08 by jsankari          #+#    #+#             */
/*   Updated: 2020/07/02 20:36:05 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sc;
	unsigned int	i;

	sc = (unsigned char*)s;
	i = 0;
	while (n)
	{
		if (sc[i] == (unsigned char)c)
		{
			return ((void*)s + i);
		}
		i++;
		n--;
	}
	return (NULL);
}
