/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:42:22 by theo              #+#    #+#             */
/*   Updated: 2025/02/01 14:38:25 by theo             ###   ########.fr       */
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

int	look_right(t_data *data)
{
	t_player	player;
	double		old_dir;
	double		old_plane;

	player = data->player;
	old_dir = player.direction.x;
	old_plane = player.plane.x;
	player.angle += player.camera_speed;
	if (player.angle > 2 * PI)
		player.angle -= 2 * PI;
	player.direction.x = player.direction.x * cos(-player.camera_speed)
		- player.direction.y * sin(-player.camera_speed);
	player.direction.y = old_dir * sin(-player.camera_speed)
		+ player.direction.y * cos(-player.camera_speed);
	player.plane.x = player.plane.x * cos(-player.camera_speed) - player.plane.y
		* sin(-player.camera_speed);
	player.plane.y = old_plane * sin(-player.camera_speed) + player.direction.y
		* cos(-player.camera_speed);
	data->player = player;
	return (0);
}

int	look_left(t_data *data)
{
	t_player	player;
	double		old_dir;
	double		old_plane;

	player = data->player;
	old_dir = player.direction.x;
	old_plane = player.plane.x;
	player.angle -= player.camera_speed;
	if (player.angle < 0)
		player.angle += 2 * PI;
	player.direction.x = player.direction.x * cos(player.camera_speed)
		- player.direction.y * sin(player.camera_speed);
	player.direction.y = old_dir * sin(player.camera_speed) + player.direction.y
		* cos(player.camera_speed);
	player.plane.x = player.plane.x * cos(player.camera_speed) - player.plane.y
		* sin(player.camera_speed);
	player.plane.y = old_plane * sin(player.camera_speed) + player.direction.y
		* cos(player.camera_speed);
	data->player = player;
	return (0);
}
