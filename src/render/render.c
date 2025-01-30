/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:41:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 19:41:44 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &render_next_frame, data);
	mlx_hook(data->win, DestroyNotify, SubstructureNotifyMask, &close_window,
		data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_pressed, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &key_released, data);
	mlx_loop(data->mlx);
}

int	render_next_frame(t_data *data)
{
	long int	current_time;

	current_time = get_current_time();
	data->loop.delta += (current_time - data->loop.last_time)
		/ data->loop.interval;
	data->loop.last_time = current_time;
	if (data->loop.delta >= 1)
	{
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->pixel.pixel, 0, 0);
		data->loop.delta--;
	}
	return (0);
}
