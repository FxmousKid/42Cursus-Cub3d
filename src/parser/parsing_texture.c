/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:36:52 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 22:05:38 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int *color, char *str)
{
	t_argb	argb;
	char	**colors;

	colors = ft_split(str, ',');
	if (colors == NULL)
		return (-1);
	argb.alpha = 0;
	argb.red = ft_atoi(colors[0]);
	argb.green = ft_atoi(colors[1]);
	argb.blue = ft_atoi(colors[2]);
	*color = argb_to_hex(argb);
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
	free(str);
	return (1);
}

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
		result = get_color(&data->floor_color, name[1]);
	else if (ft_strncmp(name[0], "C", ft_strlen(name[0])) == 0)
		result = get_color(&data->celling_color, name[1]);
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
	while (i < 6)
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
	return (free(line), 0);
}
