/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:11:34 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/25 23:04:01 by ptheo            ###   ########.fr       */
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
	int		i;

	i = 0;
	while (i < MAX_SIZE_MAP)
	{
		ft_bzero(data->map[i], MAX_SIZE_MAP);
		i++;
	}
	if (get_texture(data, fd) == -1)
		return (-1);
	if (fill_map(data, fd) == -1)
		return (-1);
	return (0);
}

int	get_texture(t_data *data, int fd)
{
	char	**line_texture;
	char	*line;

	line = get_next_line(fd);
	line_texture = ft_split(line, ' ');
	free(line);
	if (line_texture == NULL)
		return (-1);
	return (0);
}
