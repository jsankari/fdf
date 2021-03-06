/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:01:38 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 14:57:41 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((!s1[i] && !s2[i]) || !n)
		return (1);
	if (s1 && s2 && n)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && n - 1)
		{
			n--;
			i++;
		}
		if (s1[i] - s2[i] == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
