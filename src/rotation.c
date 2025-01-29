/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:34:34 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/28 16:11:14 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect	rotation_yaw(t_data *data, t_vect pos, double angle)
{
	double	n_x;
	double	n_y;

	(void)data;
	//n_x = pos.x * cos(data->player.angle) - pos.y * sin(data->player.angle);
	//n_y = pos.x * sin(data->player.angle) + pos.y * cos(data->player.angle);
	n_x = pos.x * cos(angle) - pos.y * sin(angle);
	n_y = pos.x * sin(angle) + pos.y * cos(angle);
	pos.x = n_x;
	pos.y = n_y;
	return (pos);
}

void	applie_rotation(t_data *data, double angle)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].top_left = rotation_yaw(data, data->map[y][x].top_left, angle);
			data->map[y][x].top_right = rotation_yaw(data, data->map[y][x].top_right, angle);
			data->map[y][x].bot_left = rotation_yaw(data, data->map[y][x].bot_left, angle);
			data->map[y][x].bot_right = rotation_yaw(data, data->map[y][x].bot_right, angle);			
			x++;
		}
		y++;
	}
}
