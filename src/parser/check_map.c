/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:02:02 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/11 23:01:22 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			ft_printf("%sError: %s", RED_TXT, END_TXT);
			ft_printf("Map must be surrounded by walls\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_map_format(char map[1024][1024])
{
	size_t	len_line;
	size_t	i;

	i = 0;
	len_line = ft_strlen(map[0]);
	if (!check_first_last_line(map[0]))
		return (false);
	while (map[i] && map[i + 1][0])
	{
		if (map[i][0] != '1' || map[i++][len_line - 1] != '1')
		{
			ft_printf("%sError: %s", RED_TXT, END_TXT);
			ft_printf("Map must be surrounded by walls\n");
			return (false);
		}
	}
	if (!check_first_last_line(map[i]))
		return (false);
	return (true);
}

static void	get_map(char map[1024][1024], int fd, char *line)
{
	int		i;

	i = 0;
	while (line)
	{
		ft_strlcpy(map[i], line, ft_strlen(line));
		map[i][ft_strlen(line) - 1] = '\0';
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i][0] = '\0';
}

bool	check_map(int fd)
{
	char	*line;
	char	map[1024][1024];

	line = get_next_line(fd);
	while (line && !ft_isdigit(*line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (ft_printf("%sError%s", RED_TXT, END_TXT), false);
	get_map(map, fd, line);
	if (!check_map_format(map))
		return (false);
	return (true);
}
