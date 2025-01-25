/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:38:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/25 22:23:10 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.pixel, 0, 0);
	return (0);
}
