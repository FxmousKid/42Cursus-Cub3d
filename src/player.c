/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:53:23 by theo              #+#    #+#             */
/*   Updated: 2025/01/27 04:09:51 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_data *data)
{
	t_player	player;

	player.pos = get_vect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	player.angle = 0.5;
	player.speed = 5;
	data->player = player;
	player.direction = get_vect(cos(4.5), sin(4.5), 0);
	return (0);
}

void	draw_player(t_data *data)
{
	draw_circle(data, data->player.pos, data->size / 3, GREEN_ARGB);\
	draw_line(data, get_vect(data->player.pos.x + (data->player.direction.x * 25), 
		data->player.pos.y + (data->player.direction.y * 25),
		0), data->player.pos, RED_ARGB);
}


