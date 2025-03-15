/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:00:04 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 18:38:54 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_normal_tile(t_data *data, int x, int y, char type)
{
	data->map[y][x].type = type;
	data->map[y][x].index = get_vect(x, y, 0);
	data->map[y][x].height = 100;
	if (type == '2')
	{
		data->map[y][x].door.open = false;
		data->no_door = false;
	}
	if (type == 'N' || type == 'E' || type == 'S' || type == 'W')
	{
		data->player.index = get_vect(x + 0.5, y + 0.5, 0);
		first_view_player(data, type);
		rotate_camera(data, data->player.angle);
	}
}

int	fill_map_row(t_data *data, char *line, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] == '\t')
		{
			j = 0;
			while (j++ < 4)
			{
				data->map[y][x].type = ' ';
				data->map[y][x].index = get_vect(x, y, 0);
				data->map[y][x++].height = 100;
			}
		}
		else
		{
			fill_normal_tile(data, x, y, line[i]);
			x++;
		}
		i++;
	}
	data->map[y][x].type = '\0';
	return (0);
}

int	fill_map(t_data *data, int fd)
{
	char	*line;
	int		x;
	int		y;

	line = get_next_line(fd);
	y = 0;
	data->map = (t_tile **)malloc(sizeof(t_tile *) * MAP_SIZE_MAX + 1);
	if (data->map == NULL)
		return (close_window(data), close(fd), -1);
	ft_bzero(data->map, MAP_SIZE_MAX);
	while (line)
	{
		x = 0;
		data->map[y] = (t_tile *)malloc(sizeof(t_tile) * MAP_SIZE_MAX);
		if (data->map[y] == NULL)
			return (close_window(data), close(fd), -1);
		fill_map_row(data, line, x, y);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map_height = y;
	return (0);
}
