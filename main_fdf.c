/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:06:06 by jsankari          #+#    #+#             */
/*   Updated: 2021/03/04 10:57:19 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_window(t_mom *mom)
{
	mlx_destroy_image(mom->mlx_ptr, mom->img_ptr);
	exit(0);
}

void	key_instructions(t_mom *mom)
{
	if (mom->instructions == 1)
	{
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 0, C_WHITE,
		"MOVE = ARROWS");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 20, C_WHITE,
		"ZOOM = Q/A");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 40, C_WHITE,
		"SCALE = W/S");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 60, C_WHITE,
		"PROJECTION = T");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 80, C_WHITE,
		"COLOR = G");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 100, C_WHITE,
		"SPEED = 5/8");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 120, C_WHITE,
		"RESET = R");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 140, C_WHITE,
		"HIDE/SHOW = F");
	}
}

t_mom	initialize_fdf(char **av)
{
	t_mom	mom;

	mom.win = window_struct(ft_atoi(av[2]), ft_atoi(av[3]));
	mom.maps = map_struct(0, 0, 10, 10);
	mom.spd = 10;
	if (mom.win.hei < 1 || mom.win.wid < 1)
		handle_errors(6);
	if (mom.win.hei > 2880 || mom.win.wid > 5120)
		handle_errors(7);
	mom.pos = pos_struct(mom.win.hei / 6, mom.win.wid / 6, mom.maps.clr);
	if (!(mom.mlx_ptr = mlx_init()))
		exit(0);
	mom.instructions = 1;
	mom.win_ptr = mlx_new_window(mom.mlx_ptr, mom.win.wid, mom.win.hei, av[1]);
	mom.img_ptr = mlx_new_image(mom.mlx_ptr, mom.win.wid, mom.win.hei);
	mom.pix_ray = (int*)mlx_get_data_addr(mom.img_ptr,
	&mom.b_p_p, &mom.size_line, &mom.endian);
	return (mom);
}

int		main(int ac, char **av)
{
	t_mom	mom;

	if (ac != 4)
		handle_errors(1);
	mom = initialize_fdf(av);
	validate_map(av[1], &mom);
	map_reader(av[1], &mom);
	mlx_hook(mom.win_ptr, 2, (long)1L, key_map, &mom);
	mlx_hook(mom.win_ptr, 17, 0, close_window, &mom);
	mlx_loop_hook(mom.mlx_ptr, key_hook, &mom);
	mlx_loop(mom.mlx_ptr);
	return (0);
}
