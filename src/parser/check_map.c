/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:02:02 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/12 15:31:36 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "macro.h"

bool	check_player_pos(t_map map);

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

bool	check_map_format(t_map map)
{
	size_t	len_line;
	size_t	i;

	i = 0;
	len_line = ft_strlen(map[0]);
	if (!check_first_last_line(map[0]))
		return (false);
	while (map[i] && map[i + 1][0])
	{
		if (map[i][0] != '1' || map[i][len_line - 1] != '1')
		{
			ft_printf("fail line : %s", map[i]);
			ft_printf("%sError: %s", RED_TXT, END_TXT);
			ft_printf("Map must be surrounded by walls\n");
			return (false);
		}
		i++;
	}
	if (!check_first_last_line(map[i]) || !check_player_pos(map))
		return (false);
	return (true);
}

static void	get_map(t_map map, int fd, char *line)
{
	int	i;

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
	char			*line;
	int				i;
	static t_map	map;

	i = 0;
	line = get_next_line(fd);
	while (line && i <= 8)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (!line)
		return (ft_printf("%sError%s", RED_TXT, END_TXT), false);
	get_map(map, fd, line);
	if (!check_map_format(map))
		return (false);
	return (true);
}
