/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:21:35 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/25 13:27:38 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char nbr;

	nbr = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n >= 0 && n < 10)
	{
		nbr = n + '0';
		ft_putchar(nbr);
	}
	else
	{
		ft_putnbr(n / 10);
		nbr = (n % 10 + '0');
		ft_putchar(nbr);
	}
}
