/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:41:41 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 16:41:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	if (data->pixel.pixel != NULL)
		mlx_destroy_image(data->mlx, data->pixel.pixel);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	data->win = NULL;
	if (data->mlx != NULL)
		free(data->mlx);
	data->mlx = NULL;
	exit(0);
}
