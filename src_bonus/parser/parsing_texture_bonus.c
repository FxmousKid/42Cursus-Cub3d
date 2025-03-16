/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:36:52 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/16 16:16:07 by ptheo            ###   ########.fr       */
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
		name = ft_split(line, " \t");
		result = parse_texture_utils(data, name);
		if (result == -1)
		{
			free_tab((void **)name, len_tab((void **)name));
			return (free(line), free(name), -1);
		}
		i += result;
		free(line);
		free_tab((void **)name, len_tab((void **)name));
	}
	line = get_next_line(fd);
	return (free(line), 0);
}
