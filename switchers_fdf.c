/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchers_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:36:23 by jsankari          #+#    #+#             */
/*   Updated: 2020/11/02 18:10:55 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_switcher(int *clr)
{
	if (*clr == C_RED)
		*clr = C_ORANGE;
	else if (*clr == C_ORANGE)
		*clr = C_YELLOW;
	else if (*clr == C_YELLOW)
		*clr = C_GREEN;
	else if (*clr == C_GREEN)
		*clr = C_BLUE;
	else if (*clr == C_BLUE)
		*clr = C_INDIGO;
	else if (*clr == C_INDIGO)
		*clr = C_PURPLE;
	else if (*clr == C_PURPLE)
		*clr = C_GREY;
	else if (*clr == C_GREY)
		*clr = C_RED;
}

void	instruction_switcher(int *instructions)
{
	if (*instructions == 1)
		*instructions = 0;
	else if (*instructions == 0)
		*instructions = 1;
}

void	reset_scale(t_mom *mom)
{
	mom->maps.hscale = 10;
	mom->maps.zm = 10;
}

void	reset_xy(t_mom *mom)
{
	if (mom->maps.p_type == P_2D || mom->maps.p_type == P_SIDEVIEW)
	{
		reset_scale(mom);
		mom->pos.y = mom->win.hei / 6;
		mom->pos.x = mom->win.wid / 6;
	}
	if (mom->maps.p_type == P_ISOMETRIC)
	{
		reset_scale(mom);
		mom->pos.y = mom->win.hei / 10;
		mom->pos.x = mom->win.wid / 2;
	}
	if (mom->maps.p_type == P_CHINESE)
	{
		reset_scale(mom);
		mom->pos.y = mom->win.hei;
		mom->pos.x = -mom->win.wid / 5;
	}
	if (mom->maps.p_type == P_MILITARY)
	{
		reset_scale(mom);
		mom->pos.y = -mom->win.hei / 3;
		mom->pos.x = mom->win.wid / 2;
	}
}

void	projection_switcher(int *projection_type)
{
	if (*projection_type == P_2D)
		*projection_type = P_ISOMETRIC;
	else if (*projection_type == P_ISOMETRIC)
		*projection_type = P_MILITARY;
	else if (*projection_type == P_MILITARY)
		*projection_type = P_CHINESE;
	else if (*projection_type == P_CHINESE)
		*projection_type = P_SIDEVIEW;
	else if (*projection_type == P_SIDEVIEW)
		*projection_type = P_2D;
}
