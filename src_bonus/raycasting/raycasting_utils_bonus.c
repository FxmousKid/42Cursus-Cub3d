/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:11:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/11 15:13:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect	init_length(t_vect *ray)
{
	t_vect	delta;

	if (ray->x == 0)
		delta.x = 1e30;
	else
		delta.x = fabs(1 / ray->x);
	if (ray->y == 0)
		delta.y = 1e30;
	else
		delta.y = fabs(1 / ray->y);
	return (delta);
}

void	draw_wall(t_data *data, t_ray *ray)
{
	if (ray->w_side)
		ray->proj = ray->side.y - ray->delta.y;
	else
		ray->proj = ray->side.x - ray->delta.x;
	ray->line_h = (double)SCREEN_HEIGHT / ray->proj;
	ray->min_h = SCREEN_HEIGHT / 2 - ray->line_h / 2;
	if (ray->min_h < 0)
		ray->min_h = 0;
	ray->max_h = SCREEN_HEIGHT / 2 + ray->line_h / 2;
	if (ray->max_h >= SCREEN_HEIGHT)
		ray->max_h = SCREEN_HEIGHT - 1;
	draw_texture(data, get_side_texture(data, ray), ray);
}
