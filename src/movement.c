/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:45:38 by theo              #+#    #+#             */
/*   Updated: 2025/01/28 04:33:22 by theo             ###   ########.fr       */
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
	int		y;
	int		x;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].top_left.x -= data->player.direction.x * data->player.speed;
			data->map[y][x].top_left.y -= data->player.direction.y * data->player.speed;
			data->map[y][x].top_right.x -= data->player.direction.x * data->player.speed;
			data->map[y][x].top_right.y -= data->player.direction.y * data->player.speed;
			data->map[y][x].bot_left.x -= data->player.direction.x * data->player.speed;
			data->map[y][x].bot_left.y -= data->player.direction.y * data->player.speed;
			data->map[y][x].bot_right.x -= data->player.direction.x * data->player.speed;
			data->map[y][x].bot_right.y -= data->player.direction.y * data->player.speed;
			x++;
		}
		y++;
	}
	return (0);
}


int	move_back(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].top_left.x += data->player.direction.x * data->player.speed;
			data->map[y][x].top_left.y += data->player.direction.y * data->player.speed;
			data->map[y][x].top_right.x += data->player.direction.x * data->player.speed;
			data->map[y][x].top_right.y += data->player.direction.y * data->player.speed;
			data->map[y][x].bot_left.x += data->player.direction.x * data->player.speed;
			data->map[y][x].bot_left.y += data->player.direction.y * data->player.speed;
			data->map[y][x].bot_right.x += data->player.direction.x * data->player.speed;
			data->map[y][x].bot_right.y += data->player.direction.y * data->player.speed;
			x++;
		}
		y++;
	}
	return (0);
}

int	move_left(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].top_left.x += data->player.speed;
			data->map[y][x].top_right.x += data->player.speed;
			data->map[y][x].bot_left.x += data->player.speed;
			data->map[y][x].bot_right.x += data->player.speed;
			x++;
		}
		y++;
	}
	return (0);
}

int	move_right(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			data->map[y][x].top_left.x -= data->player.speed;
			data->map[y][x].top_right.x -= data->player.speed;
			data->map[y][x].bot_left.x -= data->player.speed;
			data->map[y][x].bot_right.x -= data->player.speed;
			x++;
		}
		y++;
	}
	return (0);
}
