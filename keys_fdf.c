/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:19:56 by jsankari          #+#    #+#             */
/*   Updated: 2021/03/06 13:01:48 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_picture(int key, t_mom *mom)
{
	if (key == L_KEY_DARROW)
		mom->pos.y += mom->spd;
	else if (key == L_KEY_UARROW)
		mom->pos.y -= mom->spd;
	else if (key == L_KEY_LARROW)
		mom->pos.x -= mom->spd;
	else if (key == L_KEY_RARROW)
		mom->pos.x += mom->spd;
	else if (key == L_KEY_E && mom->spd < 30)
		mom->spd++;
	else if (key == L_KEY_D && mom->spd > 1)
		mom->spd--;
}

void	picture_scales(int key, t_mom *mom)
{
	if (key == L_KEY_Q && mom->maps.zm < mom->win.hei &&
	mom->maps.hscale < 100)
	{
		mom->maps.zm += 1;
		mom->maps.hscale += 1;
	}
	else if (key == L_KEY_A && mom->maps.zm > 2 &&
	mom->maps.hscale > -100)
	{
		mom->maps.zm -= 1;
		mom->maps.hscale -= 1;
	}
	else if (key == L_KEY_W && mom->maps.hscale < 100)
		mom->maps.hscale += 1;
	else if (key == L_KEY_S && mom->maps.hscale > -100)
		mom->maps.hscale -= 1;
}

int		key_map(int key, t_mom *mom)
{
	if ((key >= L_KEY_LARROW && key <= L_KEY_DARROW) || key == L_KEY_E ||\
	key == L_KEY_D)
		move_picture(key, mom);
	else if (key == L_KEY_G)
		color_switcher(&mom->pos.clr);
	else if (key == L_KEY_Q || key == L_KEY_A ||\
	key == L_KEY_W || key == L_KEY_S)
		picture_scales(key, mom);
	else if (key == L_KEY_T)
		projection_switcher(&mom->maps.p_type);
	else if (key == L_KEY_ESC)
		exit(0);
	else if (key == L_KEY_F)
		instruction_switcher(&mom->instructions);
	else if (key == L_KEY_R)
		reset_xy(mom);
	return (0);
}
