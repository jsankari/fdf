/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nilen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:35:13 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/30 13:03:37 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Takes integer and gives amount of numbers in return adds one for negative.
*/

int		ft_nilen(int c)
{
	int len;

	len = 1;
	if (c == -2147483648)
		return (11);
	if (c < 0)
	{
		c *= -1;
		len++;
	}
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
