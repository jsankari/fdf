/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:25:57 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/26 16:37:14 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if string is empty and prints [0] for every empty slot and \
** terminating null.
*/

#include "libft.h"

void	ft_printnull(char const *s, size_t size)
{
	char	*nul;
	size_t	chk;
	int		i;

	chk = (size + 1);
	i = 0;
	nul = "[0]";
	while (chk--)
	{
		if (s[i++] != '\0')
			return ;
	}
	i = 0;
	size++;
	while (size--)
	{
		if (s[i++] == '\0')
		{
			ft_putstr(nul);
		}
	}
	return ;
}
