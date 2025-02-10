/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:59:37 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/10 20:02:53 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	int	color;
	int	y;
	int	x;

	y = (int)data->player.index.y - 5;
	if (y < 0)
		y = 0;
	while (y < data->map_height && y < (int)data->player.index.y + 5)
	{
		x = data->player.index.x - 5;
		if (x < 0)
			x = 0;
		while (data->map[y][x].type != '\0' && x < (int)data->player.index.x
			+ 5)
		{
			if (data->map[y][x].type == '1' || data->map[y][x].type == '2')
			{
				if (data->map[y][x].type == '1')
					color = WHITE_ARGB;
				if (data->map[y][x].type == '2')
				{
					if (data->map[y][x].door.open)
						color = GREEN_ARGB;
					else
						color = RED_ARGB;
				}
				draw_square(data, get_square(get_vect((SCREEN_WIDTH - data->size
								* 11) + ((x - (data->player.index.x - 5)))
							* data->size, data->size + ((y
									- (data->player.index.y - 5))) * data->size,
							0), get_vect((SCREEN_WIDTH - data->size * 11) + ((x
									- (data->player.index.x - 5))) * data->size
							+ data->size, (data->size) + ((y
									- (data->player.index.y - 5))) * data->size,
							0), get_vect((SCREEN_WIDTH - data->size * 11) + ((x
									- (data->player.index.x - 5))) * data->size,
							(data->size) + ((y - (data->player.index.y - 5)))
							* data->size + data->size, 0),
						get_vect((SCREEN_WIDTH - data->size * 11) + ((x
									- (data->player.index.x - 5))) * data->size
							+ data->size, (data->size) + ((y
									- (data->player.index.y - 5))) * data->size
							+ data->size, 0)), color);
			}
			x++;
		}
		y++;
	}
	draw_circle(data, get_vect(SCREEN_WIDTH - (data->size * 6), data->size * 6,
			0), data->size / 4, RED_ARGB);
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
