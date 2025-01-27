/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:52:08 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/27 04:00:38 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	t_vect	current;
	int		x;
	int		y;
	
	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			current.x = (x - data->center_pos.x) * data->size + (SCREEN_WIDTH / 2 - data->size / 2);
			current.y = (y - data->center_pos.y) * data->size + (SCREEN_HEIGHT / 2 - data->size / 2);
			if (data->map[y][x].type == '0')
			{
				fill_square(data, current, BLACK_ARGB);
				draw_square(data, current, GREY_ARGB);
			}
			else if (data->map[y][x].type == '1')
			{
				fill_square(data, current, BLUE_ARGB);
				draw_square(data, current, GREY_ARGB);
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
