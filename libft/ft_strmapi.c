/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:46:31 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 16:07:56 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*rslt;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(rslt = ft_strdup(s)))
		return (NULL);
	while (rslt[i] != '\0')
	{
		rslt[i] = f(i, s[i]);
		i++;
	}
	return (rslt);
}
