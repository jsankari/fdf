/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:57:23 by jsankari          #+#    #+#             */
/*   Updated: 2020/06/30 18:20:32 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char nbr;

	nbr = 0;
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((n * (-1)), fd);
	}
	else if (n >= 0 && n < 10)
	{
		nbr = n + '0';
		write(fd, &nbr, 1);
	}
	else
	{
		ft_putnbr_fd((n / 10), fd);
		nbr = (n % 10 + '0');
		write(fd, &nbr, 1);
	}
}
