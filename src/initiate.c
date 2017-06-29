/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 01:04:32 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/15 04:23:23 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_height(char *file, int fd)
{
	char	*line;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		height++;
	close(fd);
	return (height);
}

int			get_num_width(char *line)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

int			get_num_height(t_world *world, char *file, int fd)
{
	char	*line;
	int		num_line;
	int		ran;

	ran = 0;
	num_line = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ran)
		{
			world->width = get_num_width(line);
			ran = 1;
		}
		num_line++;
	}
	close(fd);
	return (num_line);
}

t_world		*init_world(char *file)
{
	t_world *world;

	world = (t_world*)malloc(sizeof(t_world));
	world->height = get_num_height(world, file, 0);
	world->depth = 4;
	world->pos.x = 0;
	world->pos.y = 0;
	world->view.x = 10;
	world->view.y = 5;
	world->pos_x = 0;
	world->pos_y = 0;
	world->input = (int **)malloc(sizeof(int*) * world->height);
	world->map = (t_point**)malloc(sizeof(t_point*) * world->height);
	world->mlx = mlx_init();
	world->win = mlx_new_window(world->mlx, 2000, 1000, "fdf");
	return (world);
}
