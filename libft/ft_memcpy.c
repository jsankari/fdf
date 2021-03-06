/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:54:10 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 15:04:31 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = (char*)dst;
	tmp2 = (char*)src;
	i = 0;
	if (dst || src)
	{
		while (i < n)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	return (dst);
}
