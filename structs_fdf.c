/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:16:05 by jsankari          #+#    #+#             */
/*   Updated: 2020/10/29 13:11:16 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	pos_struct(int y, int x, int clr)
{
	t_pos pos;

	pos.y = y;
	pos.x = x;
	pos.clr = clr;
	return (pos);
}

t_maps	map_struct(int hei, int wid, int hscale, int zoom)
{
	t_maps maps;

	maps.mhei = hei;
	maps.mwid = wid;
	maps.zm = zoom;
	maps.hscale = hscale;
	maps.clr = C_RED;
	maps.p_type = P_2D;
	return (maps);
}

t_win	window_struct(int wid, int hei)
{
	t_win win;

	win.wid = wid;
	win.hei = hei;
	return (win);
}

t_line	line_struct(void)
{
	t_line line;

	line.x = 0;
	line.y = 0;
	line.dx = 0;
	line.dy = 0;
	line.loc = 0;
	line.step = 0;
	line.i = 1;
	return (line);
}

t_kh	kh_struct(void)
{
	t_kh	kh;

	kh.b = 0;
	kh.y = 0;
	kh.x = 0;
	return (kh);
}
