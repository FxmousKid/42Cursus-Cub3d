/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:52:08 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/27 20:15:51 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_data *data)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].pos.x = (x - data->center_pos.x) * data->size + (SCREEN_WIDTH / 2 - data->size / 2);
			data->map[y][x].pos.y = (y - data->center_pos.y) * data->size + (SCREEN_HEIGHT / 2 - data->size / 2);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			if (data->map[y][x].type == '0')
			{
				fill_square(data, data->map[y][x].pos, BLACK_ARGB);
				draw_square(data, data->map[y][x].pos, GREY_ARGB);
			}
			else if (data->map[y][x].type == '1')
			{
				fill_square(data, data->map[y][x].pos, BLUE_ARGB);
				draw_square(data, data->map[y][x].pos, GREY_ARGB);
			}
			x++;
		}
		y++;
	}
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height_map)
	{
		j = 0;
		while (data->map[i][j].type != '\0')
		{
			ft_printf("%c", data->map[i][j].type);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
