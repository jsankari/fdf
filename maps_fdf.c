/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:11:39 by jsankari          #+#    #+#             */
/*   Updated: 2021/03/04 11:32:59 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_mir	mirstruct(void)
{
	t_mir mir;

	mir.i = 0;
	mir.x = 0;
	mir.b = 0;
	return (mir);
}

int		map_int_ray(t_mom *mom)
{
	t_mir	mir;
	char	temp[20];

	mir = mirstruct();
	mom->imap = (int*)malloc(sizeof(int) * (mom->maps.mwid * mom->maps.mhei));
	ft_putnbr(mir.i);
	while (mom->map[mir.i] != '\0')
	{
		mir.x = 0;
		ft_memset(temp, 0, 11);
		while (ft_isdigit(mom->map[mir.i]) == 1 || mom->map[mir.i] == '-')
		{
			if (mir.x > 3)
				handle_errors(8);
			temp[mir.x] = mom->map[mir.i];
			mir.i++;
			mir.x++;
		}
		temp[mir.x] = '\0';
		if (temp[0] != '\0')
			mom->imap[mir.b++] = ft_atoi(temp);
		while (mom->map[mir.i] == ' ' || mom->map[mir.i] == '\n')
			mir.i++;
	}
	return (0);
}

int		map_reader(char *filename, t_mom *mom)
{
	int		fd;
	char	*temp;
	char	*line;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_errors(2);
	mom->map = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (mom->map == NULL)
			mom->map = ft_strnew(0);
		temp = ft_strjoin(mom->map, line);
		ft_strdel(&mom->map);
		mom->map = ft_strjoin(temp, " ");
		ft_strdel(&temp);
		ft_strdel(&line);
		if (ret == -1)
			handle_errors(2);
	}
	ft_strdel(&line);
	map_int_ray(mom);
	ft_strdel(&mom->map);
	close(fd);
	return (0);
}

int		validate_line(char *line, t_mom *mom)
{
	int i;

	i = 0;
	if (mom->maps.mwid == 0)
		mom->maps.mwid = ft_countstring(line, ' ');
	if (ft_countstring(line, ' ') != mom->maps.mwid)
		handle_errors(4);
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ' && line[i] != '-')
			handle_errors(3);
		if (line[i] == '-' &&
		(line[i + 1] == '-' || ft_isdigit(line[i + 1]) == 0))
			handle_errors(3);
		i++;
	}
	return (0);
}

int		validate_map(char *filename, t_mom *mom)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_errors(2);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			handle_errors(2);
		validate_line(line, mom);
		ft_strdel(&line);
		mom->maps.mhei++;
	}
	if (ret == 0 && mom->maps.mhei == 0)
		handle_errors(5);
	ft_strdel(&line);
	close(fd);
	return (0);
}
