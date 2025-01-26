/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:11:34 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/26 17:25:14 by ptheo            ###   ########.fr       */
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
	//char	**line_texture;
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
	t_tile	current;
	t_pos	pos;
	char	*line;
	int		x;
	int		y;

	line = get_next_line(fd);
	x = 0;
	while (line)
	{
		y = 0;
		while (line[y] != '\n' && line[y])
		{
			current.type = line[y];
			pos.x = x;
			pos.y = y;
			current.pos = pos;
			data->map[x][y] = current;
			if (current.type == 'N')
				data->center_pos = current.pos;
			y++;
		}
		data->map[x][y].type = '\0';
		x++;
		free(line);
		line = get_next_line(fd);
	}
	data->height_map = x;
	ft_printf("pos_x : %d pos_y : %d\n", data->center_pos.x, data->center_pos.y);
	return (-1);
}
