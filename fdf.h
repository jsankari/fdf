/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:51:17 by jsankari          #+#    #+#             */
/*   Updated: 2021/03/06 23:47:41 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "defines_fdf.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_pos
{
	int		x;
	int		y;
	int		clr;
}					t_pos;

typedef struct		s_mir
{
	size_t	i;
	size_t	x;
	size_t	b;
}					t_mir;

typedef struct		s_win
{
	int		wid;
	int		hei;
}					t_win;

typedef struct		s_maps
{
	int		x;
	int		y;
	int		b;
	int		mhei;
	int		mwid;
	int		zm;
	int		hscale;
	int		p_type;
	int		clr;
}					t_maps;

typedef struct		s_line
{
	float i;
	float step;
	float loc;
	float x;
	float y;
	float dx;
	float dy;
}					t_line;

typedef struct		s_kh
{
	int b;
	int y;
	int x;
	int tys;
	int txs;
	int tye;
	int txe;
}					t_kh;

typedef struct		s_mom
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*pix_ray;
	int				b_p_p;
	int				size_line;
	int				endian;
	char			*map;
	int				*imap;
	int				spd;
	int				instructions;
	t_kh			kh;
	t_pos			pos;
	t_win			win;
	t_maps			maps;
	t_line			line;
}					t_mom;

int					validate_map(char *line, t_mom *mom);
void				c_prj(int *x, int *y, int z, int p_type);
void				draw_line_dda(t_pos start, t_pos end, t_mom *mom);
int					close_window(t_mom *mom);
void				color_switcher(int *clr);
void				move_picture(int key, t_mom *mom);
void				reset_xy(t_mom *mom);
int					key_map(int key, t_mom *mom);
int					key_hook(t_mom *mom);
t_pos				pos_struct(int y, int x, int clr);
t_maps				map_struct(int hei, int wid, int hscale, int zoom);
t_win				window_struct(int wid, int hei);
t_line				line_struct(void);
t_kh				kh_struct(void);
int					map_reader(char *filename, t_mom *mom);
int					map_int_ray(t_mom *mom);
void				handle_errors(int errornbr);
void				key_instructions(t_mom *mom);
void				picture_scales(int key, t_mom *mom);
void				instruction_switcher(int *instructions);
void				projection_switcher(int *projection_type);

#endif
