/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 01:30:29 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/15 21:37:04 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(t_world *world, char *file, int fd)
{
	char	*line;
	int		i;
	int		j;
	char	**str;

	i = 0;
	fd = open(file, O_RDONLY);
	while (i < world->height)
	{
		get_next_line(fd, &line);
		str = ft_strsplit(line, ' ');
		world->input[i] = (int*)malloc(sizeof(int) * world->width);
		j = 0;
		while (j < world->width)
		{
			world->input[i][j] = ft_atoi(str[j]);
			j++;
		}
		i++;
	}
	close(fd);
}
