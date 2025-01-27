/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:53:23 by theo              #+#    #+#             */
/*   Updated: 2025/01/27 17:13:32 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_data *data)
{
	t_player	player;

	player.pos = get_vect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	player.angle = 3 * PI / 2;
	player.speed = 3;
	player.camera_speed = 0.05;
	player.direction = get_vect(cos(player.angle), sin(player.angle), 0);
	data->player = player;
	return (0);
}

void	draw_player(t_data *data)
{
	draw_circle(data, data->player.pos, data->size / 3, GREEN_ARGB);\
	draw_line(data, get_vect(data->player.pos.x + (data->player.direction.x * 25), 
		data->player.pos.y + (data->player.direction.y * 25),
		0), data->player.pos, RED_ARGB);
}
