/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 00:59:03 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/27 23:28:31 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keys(int keycode, t_world *world)
{
	if (keycode == 53)
	{
		mlx_destroy_window(world->mlx, world->win);
		exit(0);
	}
	else if (keycode == 126)
		world->pos.y -= 10;
	else if (keycode == 125)
		world->pos.y += 10;
    else if (keycode == 123)
		world->pos.x -= 10;
	else if (keycode == 124)
		world->pos.x += 10;
	mlx_clear_window(world->mlx, world->win);
	parse(world);
	draw(world);
    // Now create a function that loops through and frees all the mallocs
	return (0);
}

void	draw(t_world *world)
{
	draw_vertical_line(world);
	draw_horizontal_line(world);
}

int		main(int ac, char **av)
{
	t_world *world;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		exit(0);
	}
	world = init_world(av[1]);
	read_map(world, av[1], 0);
	parse(world);
	draw(world);
	mlx_key_hook(world->win, keys, world);
	mlx_loop(world->mlx);
	return (0);
}
