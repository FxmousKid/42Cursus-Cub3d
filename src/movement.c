/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:45:38 by theo              #+#    #+#             */
/*   Updated: 2025/01/27 19:35:04 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_movement(t_data *data)
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
	data->player.pos.x += data->player.direction.x * data->player.speed;
	data->player.pos.y += data->player.direction.y * data->player.speed;
	return (0);
}


int	move_back(t_data *data)
{
	data->player.pos.x -= data->player.direction.x * data->player.speed;
	data->player.pos.y -= data->player.direction.y * data->player.speed;
	return (0);
}

int	move_left(t_data *data)
{
	data->player.pos.x -= cos(data->player.angle + PI / 2) * data->player.speed;
	data->player.pos.y -= sin(data->player.angle + PI / 2) * data->player.speed;
	return (0);
}

int	move_right(t_data *data)
{
	data->player.pos.x += cos(data->player.angle + PI / 2) * data->player.speed;
	data->player.pos.y += sin(data->player.angle + PI / 2) * data->player.speed;
	return (0);
}
