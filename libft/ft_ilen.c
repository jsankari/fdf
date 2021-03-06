/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 12:14:58 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/25 14:34:08 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Takes integer and gives amount of numbers in return
*/

int		ft_ilen(int c)
{
	int len;

	len = 1;
	if (c == -2147483648)
		return (10);
	if (c < 0)
		c *= -1;
	if (c > 9)
	{
		while (c > 9)
		{
			c = c / 10;
			len++;
		}
		return (len);
	}
	return (len);
}
