/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:08:32 by theo              #+#    #+#             */
/*   Updated: 2025/02/08 18:38:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int		x;
	t_ray	*ray;
	double	camera;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera = (2 * (x / ((double)SCREEN_WIDTH))) - 1;
		ray = malloc(sizeof(t_ray) * 1);
		ray->index = x;
		ray->ray.x = data->player.direction.x + data->player.plane.x * camera;
		ray->ray.y = data->player.direction.y + data->player.plane.y * camera;
		cast_ray(data, ray);
		free(ray);
		x++;
	}
}

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

void	cast_ray(t_data *data, t_ray *ray)
{
	t_vect	map_pos;

	map_pos.x = (int)(data->player.index.x);
	map_pos.y = (int)(data->player.index.y);
	ray->map_pos.x = map_pos.x;
	ray->map_pos.y = map_pos.y;
	// printf("px : %f py : %f\n", (data->player.index.x),
	//	(data->player.index.y));
	// printf("wx : %f wy : %f\n", map_pos.x, map_pos.y);
	ray->delta = init_length(&ray->ray);
	if (ray->ray.x < 0)
	{
		ray->step.x = 1;
		ray->side.x = (map_pos.x + 1.0 - (data->player.index.x)) * ray->delta.x;
	}
	else
	{
		ray->step.x = -1;
		ray->side.x = ((data->player.index.x - map_pos.x)) * ray->delta.x;
	}
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = ((data->player.index.y) - map_pos.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (map_pos.y + 1.0 - (data->player.index.y)) * ray->delta.y;
	}
	dda_algo(data, ray, &map_pos);
}

void	dda_algo(t_data *data, t_ray *ray, t_vect *map_pos)
{
	int	wall;
	int	i;

	wall = 0;
	i = 0;
	while (!wall && i < 15)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			map_pos->x += ray->step.x;
			ray->w_side = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			map_pos->y += ray->step.y;
			ray->w_side = 1;
		}
		if (data->map[(int)map_pos->y][(int)map_pos->x].type == '1')
		{
			ray->wall = data->map[(int)map_pos->y][(int)map_pos->x];
			wall = 1;
			draw_wall(data, ray);
			break ;
		}
		i++;
	}
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
	/*
	if (ray->w_side == 0)
		draw_line(data, get_vect(ray->index, ray->min_h, 0),
			get_vect(ray->index, ray->max_h, 0), RED_ARGB);
	else
		draw_line(data, get_vect(ray->index, ray->min_h, 0),
			get_vect(ray->index, ray->max_h, 0), BLUE_ARGB);
			*/
}
