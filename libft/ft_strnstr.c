/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:27:37 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/30 19:07:44 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	i;
	int		x;

	i = 0;
	if (*ndl == 0)
		return ((char*)hay);
	while (hay[i] != '\0' && i < len)
	{
		x = 0;
		while (hay[i + x] != '\0' && hay[i + x] == ndl[x] && (i + x) < len)
		{
			if (ndl[x + 1] == '\0')
				return ((char*)hay + i);
			x++;
		}
		i++;
	}
	return (NULL);
}
