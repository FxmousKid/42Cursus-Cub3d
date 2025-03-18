/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:06 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/17 18:01:13 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "macro.h"
#include <stdbool.h>

int	init_data_aux(t_data *data)
{
	data->loop.delta_frame = 0;
	data->loop.delta_update = 0;
	data->loop.fps = 60;
	data->loop.ups = 120;
	data->loop.interval_frame = 1000 / data->loop.fps;
	data->loop.interval_update = 1000 / data->loop.ups;
	data->loop.last_time = get_current_time();
	data->size = (SCREEN_HEIGHT + SCREEN_WIDTH) / 200;
	data->fov = 90;
	data->last_pos_mouse = SCREEN_WIDTH / 2;
	data->texture_celling.img = NULL;
	data->texture_door.img = NULL;
	data->texture_east.img = NULL;
	data->texture_floor.img = NULL;
	data->texture_north.img = NULL;
	data->texture_south.img = NULL;
	data->texture_west.img = NULL;
	data->flashlight_img.img = NULL;
	data->map = NULL;
	if (get_texture(data, &data->flashlight_img,
			"./ressource/flashlight.xpm") == -1)
		return (-1);
	data->flash_img_pos = get_vect(SCREEN_WIDTH - 350, SCREEN_HEIGHT - 320, -5);
	data->no_door = true;
	return (0);
}

int	init_data(t_data *data, char *argv[])
{
	int	i;

	i = -1;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (data->win == NULL)
		return (-1);
	if (init_pixel(&data->pixel, data->mlx) == -1)
		return (-1);
	data->frame = (int **)malloc(sizeof(int *) * (SCREEN_HEIGHT));
	if (data->frame == NULL)
		return (-1);
	ft_bzero(data->frame, SCREEN_HEIGHT);
	while (++i < SCREEN_HEIGHT)
	{
		data->frame[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH);
		if (data->frame[i] == NULL)
			return (-1);
	}
	if (init_data_aux(data) == -1 || init_player(data) == -1
		|| parsing_map(data, argv[1]) == -1)
		return (-1);
	return (0);
}

bool	check_config_file(char *config_file_path);

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("%sInvalid number of arguments%s\n", RED_TXT, END_TXT);
		return (1);
	}
	if (!check_config_file(argv[1]))
		return (1);
	if (init_data(&data, argv) == -1)
		return (close_window(&data), -1);
	render_loop(&data);
	return (0);
}
