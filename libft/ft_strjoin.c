/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:26:42 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 17:02:45 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_attach(const char *s1, const char *s2, char *joined)
{
	int		i;
	int		x;
	int		lens1;
	int		lens2;

	i = 0;
	x = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	while (i < lens1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < (lens1 + lens2))
	{
		joined[i] = s2[x];
		i++;
		x++;
	}
	joined[i] = '\0';
	return (joined);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*rslt;

	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(rslt = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rslt = ft_attach(s1, s2, rslt);
	return (rslt);
}
