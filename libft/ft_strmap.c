/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:18:29 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 16:11:26 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		rslt[i] = f(s[i]);
		i++;
	}
	return (rslt);
}
