/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:41:41 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/14 23:08:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	destroy_image(t_data *data)
{
	if (data->texture_north.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_north.img);
	if (data->texture_south.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_south.img);
	if (data->texture_west.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_west.img);
	if (data->texture_east.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_east.img);
	if (data->pixel.pixel != NULL)
		mlx_destroy_image(data->mlx, data->pixel.pixel);
	if (data->texture_celling.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_celling.img);
	if (data->texture_door.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_door.img);
	if (data->texture_floor.img != NULL)
		mlx_destroy_image(data->mlx, data->texture_floor.img);
	if (data->flashlight_img.img != NULL)
		mlx_destroy_image(data->mlx, data->flashlight_img.img);
}

int	close_window(t_data *data)
{
	destroy_image(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	data->win = NULL;
	if (data->mlx != NULL)
		free(data->mlx);
	if (data->frame)
		free_tab((void **)data->frame, SCREEN_HEIGHT);
	if (data->map)
		free_tab((void **)data->map, MAP_SIZE_MAX);
	data->mlx = NULL;
	exit(0);
	return (0);
}
