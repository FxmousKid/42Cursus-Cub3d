/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:38:21 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/27 17:38:34 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	camera_movement(t_data *data)
{
	if (data->movement.look_right)
	{
		look_right(data);
	}
	if (data->movement.look_left)
	{
		look_left(data);
	}
	if (data->movement.look_up)
	{
		look_up(data);
	}
	if (data->movement.look_down)
	{
		look_down(data);
	}
	return (0);
}

int	look_right(t_data *data)
{
	t_player	player;

	player = data->player;
	player.angle += player.camera_speed;
	if (player.angle > 2 * PI)
		player.angle -= 2 * PI;
	player.direction.x = cos(player.angle);
	player.direction.y = sin(player.angle);
	data->player = player;
	return (0);
}

int	look_left(t_data *data)
{
	t_player	player;
	
	player = data->player;
	player.angle -= player.camera_speed;
	if (player.angle < 0)
		player.angle += 2 * PI;
	player.direction.x = cos(player.angle);
	player.direction.y = sin(player.angle);
	data->player = player;
	return (0);
}

int	look_up(t_data *data)
{
	(void)data;
	return (0);
}

int	look_down(t_data *data)
{
	(void)data;
	return (0);
}
