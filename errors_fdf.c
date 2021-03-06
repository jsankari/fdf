/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:09:44 by jsankari          #+#    #+#             */
/*   Updated: 2020/10/29 13:05:47 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_errors(int errornbr)
{
	if (errornbr == 1)
		ft_putstr_fd("Usage: ./fdf [map] [window_width] [window_height]\n", 2);
	else if (errornbr == 2)
		ft_putstr_fd("ERROR: Failed to open/read file.\n", 2);
	else if (errornbr == 3)
		ft_putstr_fd("ERROR: Invalid map, Wrong symbols.\n", 2);
	else if (errornbr == 4)
		ft_putstr_fd("ERROR: Invalid map, Lines are not equal length.\n", 2);
	else if (errornbr == 5)
		ft_putstr_fd("ERROR: Empty map.\n", 2);
	else if (errornbr == 6)
		ft_putstr_fd("ERROR: Invalid window size. Window height and width \
must be more than 0 for window to exist.\n", 2);
	else if (errornbr == 7)
		ft_putstr_fd("ERROR: Invalid window size. Window height must be 1-2880 \
and width must be 1-5120.\n", 2);
	else if (errornbr == 8)
		ft_putstr_fd("ERROR: Map value too large. Minimum value is -999. \
Maximum value is 9999", 2);
	exit(0);
}
