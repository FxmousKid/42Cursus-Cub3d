/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:06 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/10 16:52:25 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data, char *argv[])
{
	int	i;

	i = 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (data->win == NULL)
		return (-1);
	if (init_pixel(&data->pixel, data->mlx) == -1)
		return (-1);
	data->frame = (int **)malloc(sizeof(int *) * (SCREEN_HEIGHT));
	while (i < SCREEN_HEIGHT)
	{
		data->frame[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH);
		i++;
	}
	data->loop.delta_frame = 0;
	data->loop.delta_update = 0;
	data->loop.fps = 60;
	data->loop.ups = 120;
	data->loop.interval_frame = 1000 / data->loop.fps;
	data->loop.interval_update = 1000 / data->loop.ups;
	data->loop.last_time = get_current_time();
	data->size = (SCREEN_HEIGHT + SCREEN_WIDTH) / 200;
	printf("size : %f\n", data->size);
	data->fov = 90;
	data->last_pos_mouse = SCREEN_WIDTH / 2;
	init_player(data);
	parsing_map(data, argv[1]);
	printf("%c\n", data->texture_north.pixels[0]);
	print_map(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	init_data(&data, argv);
	printf("%c\n", data.texture_north.pixels[0]);
	render_loop(&data);
	return (0);
}
