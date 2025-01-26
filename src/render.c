/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:38:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/26 16:52:17 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &render_next_frame, data);
	mlx_loop(data->mlx);
}

int	render_next_frame(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.pixel, 0, 0);
	return (0);
}
