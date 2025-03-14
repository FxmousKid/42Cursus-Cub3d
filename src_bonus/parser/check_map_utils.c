/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:39 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/14 23:50:05 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "macro.h"

bool	check_player_pos(t_map map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_printf("%sError%s: Must have 1 player only\n", RED_TXT, END_TXT);
		return (false);
	}
	return (true);
}

bool	valid_neighbour_floor(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == '1' || c == '2'
		|| c == '0');
}

bool	check_single_floor_pos(int i, int j, t_map map)
{
	if ((i == 0) || (i > 0 && !valid_neighbour_floor(map[i - 1][j])))
		return (false);
	if ((j == 0) || (j > 0 && !valid_neighbour_floor(map[i][j - 1])))
		return (false);
	if ((j == 1023) || (j < 1024 && !valid_neighbour_floor(map[i][j + 1])))
		return (false);
	if ((i == 1023) || (i < 1024 && !valid_neighbour_floor(map[i + 1][j])))
		return (false);
	return (true);
}

bool	check_floor_positions(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == '2')
				&& !check_single_floor_pos(i, j, map))
			{
				ft_printf("%sError%s: %s\n", RED_TXT, END_TXT, FLOOR_ERR);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_all_space_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (false);
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == '0' || line[i] == '1' || line[i] == '2')
			return (true);
		i++;
	}
	return (false);
}

bool	check_invalid_tiles(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
					|| map[i][j] == 'S' || map[i][j] == '0' || map[i][j] == '1'
					|| map[i][j] == '2' || map[i][j] == ' '))
			{
				ft_printf("%sError%s: Invalid Tile found\n", RED_TXT, END_TXT);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
