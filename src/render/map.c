/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:59:37 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 19:42:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	t_vect	v;
	int		y;
	int		x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			v = get_vect(x * data->size, y * data->size, 0);
			if (data->map[y][x].type == '0' || data->map[y][x].type == 'N')
			{
				draw_square(data, get_square(v, get_vect(v.x + data->size, v.y,
							0), get_vect(v.x, v.y + data->size, 0), get_vect(v.x
							+ data->size, v.y + data->size, 0)), GREY_ARGB);
			}
			else if (data->map[y][x].type == '1')
			{
				fill_square(data, get_square(v, get_vect(v.x + data->size, v.y,
							0), get_vect(v.x, v.y + data->size, 0), get_vect(v.x
							+ data->size, v.y + data->size, 0)), BLUE_ARGB);
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
