/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:08:32 by theo              #+#    #+#             */
/*   Updated: 2025/03/11 15:17:43 by ptheo            ###   ########.fr       */
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
		ray->is_door = false;
		cast_ray(data, ray);
		free(ray);
		x++;
	}
}

void	cast_ray_utils(t_data *data, t_ray *ray, t_vect *map_pos)
{
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = ((data->player.index.y) - map_pos->y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (map_pos->y + 1.0 - (data->player.index.y))
			* ray->delta.y;
	}
}

void	cast_ray(t_data *data, t_ray *ray)
{
	t_vect	map_pos;

	map_pos.x = (int)(data->player.index.x);
	map_pos.y = (int)(data->player.index.y);
	ray->map_pos.x = map_pos.x;
	ray->map_pos.y = map_pos.y;
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
	cast_ray_utils(data, ray, &map_pos);
	dda_algo(data, ray, &map_pos);
}

int	dda_algo_check(t_data *data, t_ray *ray, t_vect *map_pos)
{
	if (data->map[(int)map_pos->y][(int)map_pos->x].type == '1')
	{
		ray->wall = data->map[(int)map_pos->y][(int)map_pos->x];
		ray->is_door = false;
		ray->map_pos.x = map_pos->x;
		ray->map_pos.y = map_pos->y;
		draw_wall(data, ray);
		return (1);
	}
	if (data->map[(int)map_pos->y][(int)map_pos->x].type == '2')
	{
		ray->wall = data->map[(int)map_pos->y][(int)map_pos->x];
		ray->map_pos.x = map_pos->x;
		ray->map_pos.y = map_pos->y;
		if (ray->wall.door.open == false)
		{
			ray->is_door = true;
			draw_wall(data, ray);
			return (1);
		}
	}
	return (0);
}

void	dda_algo(t_data *data, t_ray *ray, t_vect *map_pos)
{
	int	i;

	i = 0;
	while (i < 50)
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
		if (dda_algo_check(data, ray, map_pos))
			break ;
		i++;
	}
}
