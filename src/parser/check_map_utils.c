/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:39 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/16 15:33:05 by ptheo            ###   ########.fr       */
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
			if ((map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W'
					|| map[i][j] == 'S' || map[i][j] == 'E')
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
			|| line[i] == '0' || line[i] == '1')
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
					|| map[i][j] == ' '))
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

bool	ft_isnumbers(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (ft_printf("Wrong color argument: use numbers characters\n"),
				false);
		i++;
	}
	if (i > 3)
		return (ft_printf("Wrong color argument: numbers below 256\n"), false);
	return (true);
}
