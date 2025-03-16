/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:30:43 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 18:31:39 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	replace_tab_by_space(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			j = ft_strlen(line);
			while (j > i)
			{
				line[j + 3] = line[j];
				j--;
			}
			j = 0;
			while (j < 4)
			{
				line[i++] = ' ';
				j++;
			}
		}
		i++;
	}
}
