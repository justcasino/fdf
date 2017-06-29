/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 02:11:31 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/15 20:51:19 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse(t_world *world)
{
	int	x;
	int	y;

	y = 0;
	while (y < world->height)
	{
		x = 0;
		world->map[y] = (t_point*)malloc(sizeof(t_point) * world->width);
		while (x < world->width)
		{
			world->map[y][x].x = (x - y) * world->view.x + 1000 + world->pos.x;
			world->map[y][x].y = (x + y) * world->view.y + 500 -
				(world->input[y][x] * world->depth) + world->pos.y;
			x++;
		}
		y++;
	}
}
