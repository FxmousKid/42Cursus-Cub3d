/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:06 by inazaria          #+#    #+#             */
/*   Updated: 2025/01/31 16:43:05 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data, char *argv[])
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
	data->size = 10;
	data->fov = 90;
	init_player(data);
	parsing_map(data, argv[1]);
	print_map(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	init_data(&data, argv);
	render_loop(&data);
	return (0);
}
