/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:58:11 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 16:20:51 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rslt;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(rslt = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
	{
		rslt[i] = s[start];
		i++;
		start++;
		len--;
	}
	rslt[i] = '\0';
	return (rslt);
}
