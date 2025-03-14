/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:42:22 by theo              #+#    #+#             */
/*   Updated: 2025/02/09 22:34:00 by ptheo            ###   ########.fr       */
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
	return (0);
}

void	rotate_camera(t_data *data, double angle)
{
	t_vect	d;
	t_vect	p;

	d = data->player.direction;
	p = data->player.plane;
	data->player.direction.x = d.x * cos(angle) - d.y * sin(angle);
	data->player.direction.y = d.x * sin(angle) + d.y * cos(angle);
	data->player.plane.x = p.x * cos(angle) - p.y * sin(angle);
	data->player.plane.y = p.x * sin(angle) + p.y * cos(angle);
}

int	look_right(t_data *data)
{
	t_player	player;

	player = data->player;
	player.angle -= player.camera_speed;
	if (player.angle < 0)
		player.angle += 2 * PI;
	data->player = player;
	rotate_camera(data, -player.camera_speed);
	return (0);
}

int	look_left(t_data *data)
{
	t_player	player;

	player = data->player;
	player.angle += player.camera_speed;
	if (player.angle > 2 * PI)
		player.angle -= 2 * PI;
	data->player = player;
	rotate_camera(data, player.camera_speed);
	return (0);
}
