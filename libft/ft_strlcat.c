/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:04:10 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 16:59:27 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	rslt;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	rslt = 0;
	if (size <= dstlen)
		rslt = srclen + size;
	else
		rslt = dstlen + srclen;
	while (src[i] != '\0' && (dstlen + 1) < size)
	{
		dst[dstlen++] = src[i++];
	}
	dst[dstlen] = '\0';
	return (rslt);
}
