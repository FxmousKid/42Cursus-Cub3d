/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:06 by inazaria          #+#    #+#             */
/*   Updated: 2025/01/30 19:42:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (data->win == NULL)
		return (-1);
	if (init_pixel(&data->pixel, data->mlx) == -1)
		return (-1);
	data->loop.delta = 0;
	data->loop.fps = 60;
	data->loop.interval = 1000 / data->loop.fps;
	data->loop.last_time = get_current_time();
	data->size = 50;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	init_data(&data);
	parsing_map(&data, argv[1]);
	print_map(&data);
	render_loop(&data);
	return (0);
}
