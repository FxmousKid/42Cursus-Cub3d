/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:22:40 by theo              #+#    #+#             */
/*   Updated: 2025/03/16 20:15:19 by ptheo            ###   ########.fr       */
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
	data->movement.flash = false;
	data->movement.darklight = true;
}

int	init_player(t_data *data)
{
	t_player	player;

	player.angle = 0;
	player.speed = 0.2;
	player.camera_speed = 0.07;
	player.direction = get_vect(-1, 0, 0);
	player.plane = get_vect(0, 0.66, 0);
	data->player = player;
	init_bool_move(data);
	return (0);
}

void	first_view_player(t_data *data, char d)
{
	if (d == 'N')
		data->player.angle = PI / 2;
	else if (d == 'W')
		data->player.angle = PI;
	else if (d == 'S')
		data->player.angle = -PI / 2;
}

void	player_update(t_data *data)
{
	player_movement(data);
	camera_movement(data);
}

void	draw_player(t_data *data)
{
	(void)data;
}
