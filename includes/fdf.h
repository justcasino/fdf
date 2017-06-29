/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 01:05:03 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/15 04:43:04 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef	struct		s_world
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		**input;
	t_point	**map;
	t_point	view;
	t_point	pos;
	int		depth;
	double	pos_x;
	double	pos_y;
}					t_world;

t_world				*init_world(char *file);
void				draw_horizontal_line(t_world *world);
void				draw_vertical_line(t_world *world);
void				read_map(t_world *world, char *file, int fd);
void				parse(t_world *world);
void				draw(t_world *world);

#endif
