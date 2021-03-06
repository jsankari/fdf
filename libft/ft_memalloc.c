/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:24:41 by jsankari          #+#    #+#             */
/*   Updated: 2020/07/03 13:33:39 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dst;

	dst = (void*)malloc(sizeof(void) * size);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, size);
	return (dst);
}
