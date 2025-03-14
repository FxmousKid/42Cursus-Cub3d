/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:00:04 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/14 23:32:31 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture_utils(t_data *data, char **name)
{
	int	result;

	if (name == NULL || name[0] == NULL)
		return (0);
	if (ft_strncmp(name[0], "NO", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_north, name[1]);
	else if (ft_strncmp(name[0], "SO", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_south, name[1]);
	else if (ft_strncmp(name[0], "WE", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_west, name[1]);
	else if (ft_strncmp(name[0], "EA", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_east, name[1]);
	else if (ft_strncmp(name[0], "F", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_floor, name[1]);
	else if (ft_strncmp(name[0], "C", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_celling, name[1]);
	else if (ft_strncmp(name[0], "D", ft_strlen(name[0])) == 0)
		result = get_texture(data, &data->texture_door, name[1]);
	else
		return (0);
	return (result);
}

int	parse_texture(t_data *data, int fd)
{
	int		i;
	int		result;
	char	**name;
	char	*line;

	i = 0;
	while (i < 7)
	{
		line = get_next_line(fd);
		name = ft_split(line, ' ');
		result = parse_texture_utils(data, name);
		if (result == -1)
		{
			if (name[0])
				free(name[0]);
			return (free(line), free(name), -1);
		}
		i += result;
		free(line);
		if (name != NULL)
			free(name[0]);
		free(name);
	}
	line = get_next_line(fd);
	free(line);
	return (0);
}

int	fill_map_row(t_data *data, char *line, int x, int y)
{
	while (line[x] != '\n' && line[x])
	{
		data->map[y][x].type = line[x];
		data->map[y][x].index = get_vect(x, y, 0);
		data->map[y][x].height = 100;
		if (line[x] == '2')
			data->map[y][x].door.open = false;
		if (line[x] == 'N' || line[x] == 'E' || line[x] == 'S'
			|| line[x] == 'W')
		{
			data->player.index = get_vect(x + 0.5, y + 0.5, 0);
			first_view_player(data, line[x]);
			rotate_camera(data, data->player.angle);
		}
		x++;
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
