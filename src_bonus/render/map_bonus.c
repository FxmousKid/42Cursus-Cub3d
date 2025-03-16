/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:59:37 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 18:43:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square_map(t_data *data, int x, int y)
{
	int	color;

	if (data->map[y][x].type == '1')
		color = DARK_GREEN_ARGB;
	if (data->map[y][x].type == '2')
	{
		if (data->map[y][x].door.open)
			color = GREEN_ARGB;
		else
			color = RED_ARGB;
	}
	draw_square(data, get_square(get_vect((SCREEN_WIDTH - data->size * 11) + ((x
						- (data->player.index.x - 5))) * data->size, data->size
				+ ((y - (data->player.index.y - 5))) * data->size, 0),
			get_vect((SCREEN_WIDTH - data->size * 11) + ((x
						- (data->player.index.x - 5))) * data->size
				+ data->size, (data->size) + ((y - (data->player.index.y - 5)))
				* data->size, 0), get_vect((SCREEN_WIDTH - data->size * 11)
				+ ((x - (data->player.index.x - 5))) * data->size, (data->size)
				+ ((y - (data->player.index.y - 5))) * data->size + data->size,
				0), get_vect((SCREEN_WIDTH - data->size * 11) + ((x
						- (data->player.index.x - 5))) * data->size
				+ data->size, (data->size) + ((y - (data->player.index.y - 5)))
				* data->size + data->size, 0)), color);
}

void	draw_cross_and_player(t_data *data)
{
	draw_circle(data, get_vect(SCREEN_WIDTH - (data->size * 6), data->size * 6,
			0), data->size / 4, RED_ARGB);
	draw_circle(data, get_vect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0),
		data->size / 7, WHITE_ARGB);
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	draw_circle(data, get_vect(SCREEN_WIDTH - (data->size * 6), data->size * 6,
			0), data->size * 6, VERY_DARK_GREEN_ARGB);
	y = (int)data->player.index.y - 4;
	if (y < 0)
		y = 0;
	while (y < data->map_height && y < (int)data->player.index.y + 4)
	{
		x = data->player.index.x - 4;
		if (x < 0)
			x = 0;
		while (data->map[y][x].type != '\0' && x < (int)data->player.index.x
			+ 4)
		{
			if (data->map[y][x].type == '1' || data->map[y][x].type == '2')
				draw_square_map(data, x, y);
			x++;
		}
		y++;
	}
	draw_cross_and_player(data);
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
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
