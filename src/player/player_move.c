/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:41:28 by theo              #+#    #+#             */
/*   Updated: 2025/02/01 14:40:42 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_movement(t_data *data)
{
	t_vect	old_pos;

	old_pos = data->player.pos;
	if (data->movement.front)
	{
		move_front(data);
		if (touch_player(data))
			data->player.pos = old_pos;
	}
	if (data->movement.back)
	{
		move_back(data);
		if (touch_player(data))
			data->player.pos = old_pos;
	}
	if (data->movement.left)
	{
		move_left(data);
		if (touch_player(data))
			data->player.pos = old_pos;
	}
	if (data->movement.right)
	{
		move_right(data);
		if (touch_player(data))
			data->player.pos = old_pos;
	}
	return (0);
}

int	move_front(t_data *data)
{
	data->player.pos.x += data->player.direction.x * data->player.speed * 10;
	data->player.pos.y += data->player.direction.y * data->player.speed * 10;
	data->player.index.x += data->player.direction.x * data->player.speed;
	data->player.index.y += data->player.direction.y * data->player.speed;
	return (0);
}

int	move_back(t_data *data)
{
	data->player.pos.x -= data->player.direction.x * data->player.speed * 10;
	data->player.pos.y -= data->player.direction.y * data->player.speed * 10;
	data->player.index.x -= data->player.direction.x * data->player.speed;
	data->player.index.y -= data->player.direction.y * data->player.speed;
	return (0);
}

int	move_left(t_data *data)
{
	data->player.pos.x -= cos(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.pos.y -= sin(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.index.x -= cos(data->player.angle + PI / 2)
		* data->player.speed;
	data->player.index.y -= sin(data->player.angle + PI / 2)
		* data->player.speed;
	return (0);
}

int	move_right(t_data *data)
{
	data->player.pos.x += cos(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.pos.y += sin(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.index.x += cos(data->player.angle + PI / 2)
		* data->player.speed;
	data->player.index.y += sin(data->player.angle + PI / 2)
		* data->player.speed;
	return (0);
}
