/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:41:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 16:36:39 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_loop(t_data *data)
{
	mlx_mouse_hide(data->mlx, data->win);
	mlx_loop_hook(data->mlx, &render_next_frame, data);
	mlx_hook(data->win, DestroyNotify, SubstructureNotifyMask, &close_window,
		data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_pressed, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &key_released, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, &mouse_motion, data);
	mlx_loop(data->mlx);
}

void	update_frame(t_data *data)
{
	player_update(data);
}

int	render_next_frame(t_data *data)
{
	long int	current_time;

	current_time = get_current_time();
	data->loop.delta_update += (current_time - data->loop.last_time)
		/ data->loop.interval_update;
	data->loop.delta_frame += (current_time - data->loop.last_time)
		/ data->loop.interval_frame;
	data->loop.last_time = current_time;
	if (data->loop.delta_update >= 1)
	{
		update_frame(data);
		floor_celling_raycasting(data);
		raycasting(data);
		draw_flashlight_image(data);
		data->loop.delta_update--;
	}
	if (data->loop.delta_frame >= 1)
	{
		draw_frame(data);
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->pixel.pixel, 0, 0);
		data->loop.delta_frame--;
	}
	return (0);
}

void	draw_frame(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT - 1)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel(data, x, y, data->frame[y][x]);
			x++;
		}
		y++;
	}
}
