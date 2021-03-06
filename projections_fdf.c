/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:41:22 by jsankari          #+#    #+#             */
/*   Updated: 2020/10/29 14:32:02 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_p(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	military_p(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.7862975);
	*y = -z + (previous_x + previous_y) * sin(0.7862975);
}

void	chinese_scroll_p(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x + 0.5 * previous_y * cos(0.523599);
	*y = -z + 0.5 * previous_y * sin(0.523599);
}

void	side_view_p(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x + -z / 2;
	*y = previous_y + -z / 4;
}

void	c_prj(int *x, int *y, int z, int p_type)
{
	if (p_type == P_ISOMETRIC)
		isometric_p(x, y, z);
	else if (p_type == P_CHINESE)
		chinese_scroll_p(x, y, z);
	else if (p_type == P_MILITARY)
		military_p(x, y, z);
	else if (p_type == P_SIDEVIEW)
		side_view_p(x, y, z);
}
