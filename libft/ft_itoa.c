/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:51:50 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/25 16:21:04 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*rslt;
	int		i;

	i = ft_nilen(n);
	rslt = (char*)malloc(sizeof(char) * (i + 1));
	if (rslt == NULL)
		return (NULL);
	if (n < 0)
	{
		rslt[0] = '-';
		if (n == -2147483648)
		{
			rslt[1] = (2 + 48);
			n += 2000000000;
		}
		n *= -1;
	}
	rslt[i--] = '\0';
	while (n >= 10)
	{
		rslt[i--] = ((n % 10) + 48);
		n /= 10;
	}
	rslt[i] = (n + 48);
	return (rslt);
}
