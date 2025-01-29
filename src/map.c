/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:52:08 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/28 16:56:31 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].top_left.x = (x - data->center_pos.x) * data->size;
			data->map[y][x].top_left.y = (y - data->center_pos.y) * data->size;
			data->map[y][x].top_right.x = data->map[y][x].top_left.x
				+ data->size;
			data->map[y][x].top_right.y = data->map[y][x].top_left.y;
			data->map[y][x].bot_left.x = data->map[y][x].top_left.x;
			data->map[y][x].bot_left.y = data->map[y][x].top_left.y
				+ data->size;
			data->map[y][x].bot_right.x = data->map[y][x].top_left.x
				+ data->size;
			data->map[y][x].bot_right.y = data->map[y][x].top_left.y
				+ data->size;
			x++;
		}
		y++;
	}
}

t_tile	focus_middle(t_data *data, t_tile tile)
{
	t_tile	square;

	square = tile;
	square.top_left = get_vect(square.top_left.x + (SCREEN_WIDTH / 2
				- data->size / 2), square.top_left.y + (SCREEN_HEIGHT / 2
				- data->size / 2), 0);
	square.top_right = get_vect(square.top_right.x + (SCREEN_WIDTH / 2
				- data->size / 2), square.top_right.y + (SCREEN_HEIGHT / 2
				- data->size / 2), 0);
	square.bot_left = get_vect(square.bot_left.x + (SCREEN_WIDTH / 2
				- data->size / 2), square.bot_left.y + (SCREEN_HEIGHT / 2
				- data->size / 2), 0);
	square.bot_right = get_vect(square.bot_right.x + (SCREEN_WIDTH / 2
				- data->size / 2), square.bot_right.y + (SCREEN_HEIGHT / 2
				- data->size / 2), 0);
	return (square);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			if (data->map[y][x].type == '0')
			{
				draw_square(data, focus_middle(data, data->map[y][x]),
					GREY_ARGB);
			}
			else if (data->map[y][x].type == '1')
			{
				fill_square(data, focus_middle(data, data->map[y][x]),
					BLUE_ARGB);
				draw_square(data, focus_middle(data, data->map[y][x]),
					BLUE_ARGB);
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
