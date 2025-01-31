/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:08:32 by theo              #+#    #+#             */
/*   Updated: 2025/01/31 05:02:26 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect	norm_vector(t_vect vect)
{
	int	length;

	length = sqrt(vect.x * vect.x + vect.y * vect.y);
	return (get_vect(vect.x / length, vect.y / length, 0));
}

void	raycasting(t_data *data)
{
	t_ray	*ray;
	double	angle;

	angle = data->player.angle - PI / 4;
	while (angle <= data->player.angle + PI / 4)
	{
		ray = malloc(sizeof(t_ray) * 1);
		ray->ray = get_vect(cos(angle), sin(angle), 0);
		cast_ray(data, ray);
		free(ray);
		angle += 0.001;
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

	map_pos.x = data->player.pos.x / data->size;
	map_pos.y = data->player.pos.y / data->size;
	ray->delta = init_length(&ray->ray);
	if (ray->ray.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = ((data->player.pos.x / data->size) - map_pos.x)
			* ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (map_pos.x + 1.0 - (data->player.pos.x / data->size))
			* ray->delta.x;
	}
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = ((data->player.pos.y / data->size) - map_pos.y)
			* ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (map_pos.y + 1.0 - (data->player.pos.y / data->size))
			* ray->delta.y;
	}
	dda_algo(data, ray, &map_pos);
}

void	dda_algo(t_data *data, t_ray *ray, t_vect *map_pos)
{
	t_vect	pos;
	int		wall;
	int		i;

	// int	side;
	wall = 0;
	i = 0;
	while (!wall && i < 10)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			map_pos->x += ray->step.x;
			// side = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			map_pos->y += ray->step.y;
			// side = 1;
		}
		if (data->map[(int)map_pos->y][(int)map_pos->x].type == '1')
		{
			ray->wall = data->map[(int)map_pos->y][(int)map_pos->x];
			wall = 1;
			pos = get_vect(data->player.pos.x + ray->ray.x * data->size
					* ray->side.x, data->player.pos.y + ray->ray.y * data->size
					* ray->side.y, 0);
			draw_line(data, data->player.pos, pos, RED_ARGB);
			// draw_circle(data, pos, 5, RED_ARGB);
			break ;
		}
		i++;
	}
}
