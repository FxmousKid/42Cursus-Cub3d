/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:39 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/12 21:37:41 by inazaria         ###   ########.fr       */
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
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' \
			|| map[i][j] == 'W')
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

bool	check_single_floor_pos(int i, int j, t_map map)
{
	if (i > 0 && map[i - 1][j] == ' ')
		return (false);
	if (j > 0 && map[i][j - 1] == ' ')
		return (false);
	if (j < 1024 && map[i][j + 1] == ' ')
		return (false);
	if (i < 1024 && map[i + 1][j] == ' ')
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
			if (map[i][j] == '0' && !check_single_floor_pos(i, j, map))
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
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' \
				|| map[i][j] == 'S' || map[i][j] == '0' || map[i][j] == '1' \
				|| map[i][j] == '2' || map[i][j] == ' ')
				return (true);
			ft_printf("%sError%s: Invalid Tile found", RED_TXT, END_TXT);
			return (false);
			j++;
		}
		i++;
	}
	return (true);
}
