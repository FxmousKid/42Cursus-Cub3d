/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:02:02 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/16 14:27:22 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "macro.h"

bool		check_player_pos(t_map map);

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

bool		check_invalid_tiles(t_map map);
bool		check_floor_positions(t_map map);

bool	check_map_border(t_map map)
{
	size_t	i;
	size_t	j;

	if (!check_first_last_line(map[0]))
		return (false);
	i = 0;
	while (map[i + 1][0])
	{
		j = 0;
		while (map[i][j++] == ' ')
			;
		j--;
		if (map[i][j] != '1' || map[i][ft_strlen(map[i] + j) - 1 + j] != '1')
		{
			ft_printf("%sError: %s%s\n", RED_TXT, END_TXT, MAP_WALL_ERR);
			return (false);
		}
		i++;
	}
	if (!check_first_last_line(map[i]))
		return (false);
	return (true);
}

bool	check_map_format(t_map map)
{
	if (!check_invalid_tiles(map))
		return (false);
	if (!check_player_pos(map))
		return (false);
	if (!check_floor_positions(map))
		return (false);
	return (true);
}

bool		check_all_space_line(char *line);

static bool	get_map(t_map map, int fd, char *line)
{
	int	i;

	i = 0;
	while (line)
	{
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		if (!check_all_space_line(map[i]))
		{
			return (free(line), ft_printf("%sError%s: Empty line in map\n",
					RED_TXT, END_TXT), false);
		}
		if (map[i][ft_strlen(line) - 1] == '\n')
			map[i][ft_strlen(line) - 1] = '\0';
		replace_tab_by_space(map[i]);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i][0] = '\0';
	return (true);
}

bool	check_map(int fd, int pos_map)
{
	char			*line;
	int				i;
	static t_map	map;

	i = 0;
	line = get_next_line(fd);
	while (line && i <= pos_map + 1)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (!line)
		return (ft_printf("%sError%s", RED_TXT, END_TXT), false);
	if (!get_map(map, fd, line))
		return (false);
	if (!check_map_format(map))
		return (false);
	return (true);
}
