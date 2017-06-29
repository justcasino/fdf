/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 02:26:37 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/15 20:52:41 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vert_line(int dx, int dy, t_world *world)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	x = (double)dx / (double)(abs(dy));
	y = (double)dy / (double)(abs(dy));
	while (i++ <= (abs(dy)))
	{
		mlx_pixel_put(world->mlx, world->win, (int)world->pos_x,
		(int)(world->pos_y + 1.5), 0x0FFFFF);
		world->pos_x += x;
		world->pos_y += y;
	}
}

void	horiz_line(int dx, int dy, t_world *world)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	x = (double)dx / (double)(abs(dx));
	y = (double)dy / (double)(abs(dx));
	while (i++ <= (abs(dx)))
	{
		mlx_pixel_put(world->mlx, world->win, (int)world->pos_x,
			(int)(world->pos_y + 1.5), 0x0FFFFF);
		world->pos_x += x;
		world->pos_y += y;
	}
}

void	draw_line(t_world *world, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	world->pos_x = p1.x;
	world->pos_y = p1.y;
	abs(dy) > abs(dx) ? vert_line(dx, dy, world) : horiz_line(dx, dy, world);
}

void	draw_vertical_line(t_world *world)
{
	int	x;
	int	y;

	y = 0;
	while (y < world->height - 1)
	{
		x = 0;
		while (x < world->width - 1)
		{
			draw_line(world, world->map[y][x], world->map[y][x + 1]);
			x++;
		}
		draw_line(world, world->map[y][world->width - 1],
			world->map[y + 1][world->width - 1]);
		y++;
	}
}

void	draw_horizontal_line(t_world *world)
{
	int	x;
	int	y;

	x = 0;
	while (x < world->width - 1)
	{
		y = 0;
		while (y < world->height - 1)
		{
			draw_line(world, world->map[y][x], world->map[y + 1][x]);
			y++;
		}
		draw_line(world, world->map[world->height - 1][x],
			world->map[world->height - 1][x + 1]);
		x++;
	}
}
