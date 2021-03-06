/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:24:49 by jsankari          #+#    #+#             */
/*   Updated: 2020/07/09 11:22:53 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rslt;
	size_t	i;

	i = 0;
	rslt = (char*)malloc(sizeof(char) * (size + 1));
	if (rslt == NULL)
		return (NULL);
	while (i < size)
	{
		rslt[i] = 0;
		i++;
	}
	rslt[i] = 0;
	return (rslt);
}
