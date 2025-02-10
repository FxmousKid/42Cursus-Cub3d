/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:41:28 by theo              #+#    #+#             */
/*   Updated: 2025/02/10 19:41:52 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_movement(t_data *data)
{
	if (data->movement.front)
	{
		move_front(data);
	}
	if (data->movement.back)
	{
		move_back(data);
	}
	if (data->movement.left)
	{
		move_left(data);
	}
	if (data->movement.right)
	{
		move_right(data);
	}
	return (0);
}

int	move_front(t_data *data)
{
	t_player	p;

	p = data->player;
	if (data->map[(int)(p.index.y + p.direction.y * p.speed)][(int)(p.index.x
			- p.direction.x * p.speed)].type == '1'
		|| (data->map[(int)(p.index.y + p.direction.y
				* p.speed)][(int)(p.index.x - p.direction.x
				* p.speed)].type == '2' && data->map[(int)(p.index.y
				+ p.direction.y * p.speed)][(int)(p.index.x - p.direction.x
				* p.speed)].door.open == false))
	{
		return (-1);
	}
	data->player.pos.x -= data->player.direction.x * data->player.speed * 10;
	data->player.pos.y += data->player.direction.y * data->player.speed * 10;
	data->player.index.x -= data->player.direction.x * data->player.speed;
	data->player.index.y += data->player.direction.y * data->player.speed;
	return (0);
}

int	move_back(t_data *data)
{
	t_player	p;

	p = data->player;
	if (data->map[(int)(p.index.y - p.direction.y * p.speed)][(int)(p.index.x
			+ p.direction.x * p.speed)].type == '1'
		|| (data->map[(int)(p.index.y - p.direction.y
				* p.speed)][(int)(p.index.x + p.direction.x
				* p.speed)].type == '2' && data->map[(int)(p.index.y
				- p.direction.y * p.speed)][(int)(p.index.x + p.direction.x
				* p.speed)].door.open == false))
	{
		return (-1);
	}
	data->player.pos.x += data->player.direction.x * data->player.speed * 10;
	data->player.pos.y -= data->player.direction.y * data->player.speed * 10;
	data->player.index.x += data->player.direction.x * data->player.speed;
	data->player.index.y -= data->player.direction.y * data->player.speed;
	return (0);
}

int	move_left(t_data *data)
{
	t_player	p;

	p = data->player;
	if (data->map[(int)(p.index.y - sin(data->player.angle + PI / 2)
			* p.speed)][(int)(p.index.x + cos(data->player.angle + PI / 2)
			* p.speed)].type == '1' || (data->map[(int)(p.index.y
				- sin(data->player.angle + PI / 2) * p.speed)][(int)(p.index.x
				+ cos(data->player.angle + PI / 2) * p.speed)].type == '2'
			&& data->map[(int)(p.index.y - sin(data->player.angle + PI / 2)
				* p.speed)][(int)(p.index.x + cos(data->player.angle + PI / 2)
				* p.speed)].door.open == false))
	{
		return (-1);
	}
	data->player.pos.x += cos(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.pos.y -= sin(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.index.x += cos(data->player.angle + PI / 2)
		* data->player.speed;
	data->player.index.y -= sin(data->player.angle + PI / 2)
		* data->player.speed;
	return (0);
}

int	move_right(t_data *data)
{
	t_player	p;

	p = data->player;
	if (data->map[(int)(p.index.y + sin(data->player.angle + PI / 2)
			* p.speed)][(int)(p.index.x - cos(data->player.angle + PI / 2)
			* p.speed)].type == '1' || (data->map[(int)(p.index.y
				+ sin(data->player.angle + PI / 2) * p.speed)][(int)(p.index.x
				- cos(data->player.angle + PI / 2) * p.speed)].type == '2'
			&& data->map[(int)(p.index.y + sin(data->player.angle + PI / 2)
				* p.speed)][(int)(p.index.x - cos(data->player.angle + PI / 2)
				* p.speed)].door.open == false))
	{
		return (-1);
	}
	data->player.pos.x -= cos(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.pos.y += sin(data->player.angle + PI / 2) * data->player.speed
		* 10;
	data->player.index.x -= cos(data->player.angle + PI / 2)
		* data->player.speed;
	data->player.index.y += sin(data->player.angle + PI / 2)
		* data->player.speed;
	return (0);
}
