/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:02:30 by jsankari          #+#    #+#             */
/*   Updated: 2020/07/01 13:25:02 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int x;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		x = 0;
		while (haystack[i + x] != '\0' && haystack[i + x] == needle[x])
		{
			if (needle[x + 1] == '\0')
				return ((char*)haystack + i);
			x++;
		}
		i++;
	}
	return (NULL);
}
