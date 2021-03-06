/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:21:13 by jsankari          #+#    #+#             */
/*   Updated: 2020/10/29 14:02:40 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_loc(t_pos start, t_mom *mom)
{
	while (mom->line.i <= mom->line.step)
	{
		if (mom->line.x >= 0 && mom->line.x < mom->win.wid)
		{
			mom->line.loc = (int)mom->line.y * mom->win.wid + (int)mom->line.x;
			if (mom->line.loc >= 0 && mom->line.loc < mom->win.wid *
			mom->win.hei)
				mom->pix_ray[(int)mom->line.loc] = start.clr;
		}
		mom->line.y += mom->line.dy;
		mom->line.x += mom->line.dx;
		mom->line.i++;
	}
}

void	draw_line_dda(t_pos start, t_pos end, t_mom *mom)
{
	mom->line = line_struct();
	mom->line.dx = end.x - start.x;
	mom->line.dy = end.y - start.y;
	if (fabsf(mom->line.dx) >= fabsf(mom->line.dy))
		mom->line.step = fabsf(mom->line.dx);
	else
		mom->line.step = fabsf(mom->line.dy);
	mom->line.dx /= mom->line.step;
	mom->line.dy /= mom->line.step;
	mom->line.x = start.x;
	mom->line.y = start.y;
	calculate_loc(start, mom);
}

void	horizontal_line(t_mom *mom)
{
	mom->kh.txe = mom->pos.x + mom->kh.x + 1 + mom->maps.zm;
	mom->kh.tye = mom->pos.y + mom->kh.y;
	c_prj(&mom->kh.txe, &mom->kh.tye,
	mom->imap[mom->kh.b + 1] * mom->maps.hscale, mom->maps.p_type);
	draw_line_dda(pos_struct(mom->kh.tys, mom->kh.txs, mom->pos.clr),
	pos_struct(mom->kh.tye, mom->kh.txe, mom->pos.clr), mom);
}

void	vertical_line(t_mom *mom)
{
	mom->kh.txe = mom->pos.x + mom->kh.x;
	mom->kh.tye = mom->pos.y + mom->kh.y + 1 + mom->maps.zm;
	c_prj(&mom->kh.txe, &mom->kh.tye,
	mom->imap[mom->kh.b + mom->maps.mwid] * mom->maps.hscale, mom->maps.p_type);
	draw_line_dda(pos_struct(mom->kh.tys, mom->kh.txs, mom->pos.clr),
	pos_struct(mom->kh.tye, mom->kh.txe, mom->pos.clr), mom);
}

int		key_hook(t_mom *mom)
{
	mom->kh = kh_struct();
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while (mom->kh.b < mom->maps.mhei * mom->maps.mwid)
	{
		if (mom->kh.x == mom->maps.mwid * mom->maps.zm)
		{
			mom->kh.y += mom->maps.zm;
			mom->kh.x = 0;
		}
		mom->kh.tys = mom->pos.y + mom->kh.y;
		mom->kh.txs = mom->pos.x + mom->kh.x;
		c_prj(&mom->kh.txs, &mom->kh.tys, mom->imap[mom->kh.b]
		* mom->maps.hscale, mom->maps.p_type);
		if (mom->kh.x != (mom->maps.mwid - 1) * mom->maps.zm)
			horizontal_line(mom);
		if (mom->kh.y < (mom->maps.mhei - 1) * mom->maps.zm)
			vertical_line(mom);
		mom->kh.x += mom->maps.zm;
		mom->kh.b++;
	}
	mlx_put_image_to_window(mom->mlx_ptr, mom->win_ptr, mom->img_ptr, 0, 0);
	if (mom->instructions == 1)
		key_instructions(mom);
	return (0);
}
