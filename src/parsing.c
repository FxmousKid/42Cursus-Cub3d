/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:11:34 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 01:11:02 by theo             ###   ########.fr       */
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
	ft_bzero(data->map, MAX_SIZE_MAP);
	if (get_texture(data, fd) == -1)
		return (-1);
	if (fill_map(data, fd) == -1)
		return (-1);
	return (0);
}

int	get_texture(t_data *data, int fd)
{
	char	*line;

	// char	**line_texture;
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
	t_tile	current;
	t_vect	pos;
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
			current.type = line[x];
			pos.x = x;
			pos.y = y;
			pos.z = 0;
			current.top_left = pos;
			current.top_right = get_vect(pos.x + data->size, pos.y, 0);
			current.bot_left = get_vect(pos.x, pos.y + data->size, 0);
			current.bot_right = get_vect(pos.x + data->size, pos.y + data->size,
					0);
			data->map[y][x] = current;
			if (current.type == 'N')
			{
				data->map[y][x].type = '0';
				data->center_pos = current.top_left;
				data->player.index.x = x + data->size / 2;
				data->player.index.y = y + data->size / 2;
			}
			x++;
		}
		data->map[y][x].type = '\0';
		y++;
		free(line);
		line = get_next_line(fd);
	}
	data->height_map = y;
	return (-1);
}
