/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:44:13 by jsankari          #+#    #+#             */
/*   Updated: 2020/10/22 21:34:21 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char *s, int c)
{
	char	*rslt;
	int		a;
	int		o;

	a = 0;
	o = 0;
	if (!(s))
		return (0);
	o = (ft_strlen(s) - 1);
	if (s[a] != '\0')
	{
		while (s[a] == c && s[a] != '\0')
			a++;
		while (s[o] == c && o > a)
			o--;
		if (!(rslt = ft_strsub(s, a, (o - a + 1))))
			return (NULL);
		free(s);
	}
	else
		return ((char*)s);
	return (rslt);
}
