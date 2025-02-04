/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:19:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/04 04:37:50 by theo             ###   ########.fr       */
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
	if (parse_texture(data, fd) == -1)
		return (-1);
	if (fill_map(data, fd) == -1)
		return (-1);
	return (0);
}

int	parse_texture(t_data *data, int fd)
{
	char	**name;
	char	*line;

	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd);
		name = ft_split(line, ' ');
		if (ft_strncmp(name[0], "NO", ft_strlen(name[0])))
		{
			data->texture_north = get_texture(data, name[1]);
		}
		else if (ft_strncmp(name[0], "SO", ft_strlen(name[0])))
		{
			data->texture_south = get_texture(data, name[1]);
		}
		else if (ft_strncmp(name[0], "WE", ft_strlen(name[0])))
		{
			data->texture_west = get_texture(data, name[1]);
		}
		else if (ft_strncmp(name[0], "EA", ft_strlen(name[0])))
		{
			data->texture_west = get_texture(data, name[1]);
		}
		else
			return (-1);
		free(line);
	}
	for (int j = 0; j < 4; j++)
	{
		line = get_next_line(fd);
		free(line);
	}
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
