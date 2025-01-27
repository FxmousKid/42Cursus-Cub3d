/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:45:38 by theo              #+#    #+#             */
/*   Updated: 2025/01/27 04:09:15 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


int	look_right(t_data *data)
{
	t_player	player;
	
	player = data->player;
	player.angle += 0.1;
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
	player.angle -= 0.1;
	if (player.angle < 0)
		player.angle += 2 * PI;
	player.direction.x = cos(player.angle);
	player.direction.y = sin(player.angle);
	data->player = player;
	return (0);
}
