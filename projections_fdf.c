/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:41:22 by jsankari          #+#    #+#             */
/*   Updated: 2022/06/09 14:11:18 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_p(int *x, int *y, int z)
{
	int old_x;
	int old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = -z + (old_x + old_y) * sin(0.523599);
}

void	military_p(int *x, int *y, int z)
{
	int old_x;
	int old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.7862975);
	*y = -z + (old_x + old_y) * sin(0.7862975);
}

void	chinese_scroll_p(int *x, int *y, int z)
{
	int old_x;
	int old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x + 0.5 * old_y * cos(0.523599);
	*y = -z + 0.5 * old_y * sin(0.523599);
}

void	side_view_p(int *x, int *y, int z)
{
	int old_x;
	int old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x + -z / 2;
	*y = old_y + -z / 4;
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
