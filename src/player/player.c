/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:22:40 by theo              #+#    #+#             */
/*   Updated: 2025/02/01 14:54:12 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_bool_move(t_data *data)
{
	data->movement.back = false;
	data->movement.front = false;
	data->movement.left = false;
	data->movement.right = false;
	data->movement.look_left = false;
	data->movement.look_right = false;
}

int	init_player(t_data *data)
{
	t_player	player;

	player.angle = 3 * PI / 2;
	player.speed = 0.2;
	player.camera_speed = 0.1;
	player.direction = get_vect(-1, 0, 0);
	player.plane = get_vect(0, 0.66, 0);
	data->player = player;
	init_bool_move(data);
	return (0);
}

void	player_update(t_data *data)
{
	player_movement(data);
	camera_movement(data);
}

void	draw_player(t_data *data)
{
	draw_circle(data, data->player.pos, data->size / 3, GREEN_ARGB);
	draw_line(data, data->player.pos, get_vect(data->player.pos.x
			+ data->player.direction.x * 20, data->player.pos.y
			+ data->player.direction.y * 20, 0), RED_ARGB);
}