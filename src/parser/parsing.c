/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:19:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/03 04:01:46 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len <= 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (-1);
	return (0);
}

int	parsing_map(t_data *data, char *file_map)
{
	int	fd_map;

	fd_map = open(file_map, O_RDONLY);
	if (check_file_name(file_map) == -1 || fd_map <= 0)
		return (-1);
	if (parse_file(data, fd_map) == -1)
		return (-1);
	return (0);
}

int	parse_file(t_data *data, int fd)
{
	ft_bzero(data->map, MAP_SIZE_MAX);
	if (get_texture(data, fd) == -1)
		return (-1);
	if (fill_map(data, fd) == -1)
		return (-1);
	return (0);
}

int	get_texture(t_data *data, int fd)
{
	char	*line;

	for (int i = 0; i < 8; i++)
	{
		line = get_next_line(fd);
		free(line);
	}
	(void)data;
	return (0);
}

int	fill_map(t_data *data, int fd)
{
	char	*line;
	int		x;
	int		y;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		while (line[x] != '\n' && line[x])
		{
			data->map[y][x].type = line[x];
			data->map[y][x].index = get_vect(x, y, 0);
			data->map[y][x].height = 100;
			// data->map[y][len - x].pos = get_vect(x * data->size, y
			//		* data->size,
			//	0);
			if (line[x] == 'N' || line[x] == 'E' || line[x] == 'S'
				|| line[x] == 'W')
			{
				data->player.index = get_vect(x, y, 0);
				first_view_player(data, line[x]);
				rotate_camera(data, data->player.angle);
			}
			x++;
		}
		data->map[y][x].type = '\0';
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map_height = y;
	return (0);
}
