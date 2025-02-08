/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_celling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:55:56 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/08 18:48:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_celling_raycasting(t_data *data)
{
	t_floor	floor;
	int		i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		floor.y = i;
		floor.ray_dir0 = get_vect(data->player.direction.x
				- data->player.plane.x, data->player.direction.y
				- data->player.plane.y, 0);
		floor.ray_dir1 = get_vect(data->player.direction.x
				+ data->player.plane.x, data->player.direction.y
				+ data->player.plane.y, 0);
		floor.p = i - SCREEN_HEIGHT / 2;
		floor.posz = 0.5 * SCREEN_HEIGHT;
		draw_floor_celling(data, &floor);
		i++;
	}
}

void	draw_floor_celling(t_data *data, t_floor *side)
{
	t_vect			floor_step;
	t_vect			floor_pos;
	t_vect			texture_cor1;
	t_vect			texture_cor2;
	float			row;
	int				i;
	unsigned int	color;

	i = 0;
	row = side->posz / side->p;
	floor_step = get_vect(row * (side->ray_dir0.x - side->ray_dir1.x)
			/ SCREEN_WIDTH, row * (side->ray_dir1.y - side->ray_dir0.y)
			/ SCREEN_WIDTH, 0);
	floor_pos = get_vect(data->player.index.x - row * side->ray_dir0.x,
			data->player.index.y + row * side->ray_dir0.y, 0);
	while (i < SCREEN_WIDTH)
	{
		texture_cor1 = get_vect((int)(((double)data->texture_floor.width
						* (double)(floor_pos.x
							- floor(floor_pos.x)))) & (data->texture_floor.width
					- 1), (int)((double)data->texture_floor.height
					* (double)(floor_pos.y
						- floor(floor_pos.y))) & (data->texture_floor.height
					- 1), 0);
		texture_cor2 = get_vect((int)((double)data->texture_celling.width
					* (floor_pos.x
						- (int)floor_pos.x)) & (data->texture_celling.width
					- 1), (int)((double)data->texture_celling.height
					* (floor_pos.y
						- (int)floor_pos.y)) & (data->texture_celling.height
					- 1), 0);
		floor_pos.x += floor_step.x;
		floor_pos.y += floor_step.y;
		color = texture_cor1.y * data->texture_floor.line_size + texture_cor1.x
			* (data->texture_floor.bits_per_pixel / 8);
		put_pixel(data, i, side->y, *(int *)(data->texture_floor.pixels
				+ color));
		color = texture_cor2.y * data->texture_celling.line_size
			+ texture_cor2.x * (data->texture_celling.bits_per_pixel / 8);
		put_pixel(data, i, SCREEN_HEIGHT - side->y - 1,
			*(int *)(data->texture_celling.pixels + color));
		i++;
	}
}

void	floor_and_celling_casting(t_data *data, t_ray *ray)
{
	t_vect floor_wpos;
	t_vect current_floor;
	t_vect text_pos;
	double dist_player;
	double dist_wall;
	double current_dist;
	double weight;
	int y;

	if (ray->w_side == 0 && ray->ray.x > 0)
	{
		floor_wpos.x = ray->map_pos.x;
		floor_wpos.y = ray->map_pos.y + ray->wall_x;
	}
	else if (ray->w_side == 0 & ray->ray.x < 0)
	{
		floor_wpos.x = ray->map_pos.x + 1.0;
		floor_wpos.y = ray->map_pos.y + ray->wall_x;
	}
	else if (ray->w_side == 1 && ray->ray.y > 0)
	{
		floor_wpos.x = ray->map_pos.x + ray->wall_x;
		floor_wpos.y = ray->map_pos.y;
	}
	else
	{
		floor_wpos.x = ray->map_pos.x + ray->wall_x;
		floor_wpos.y = ray->map_pos.y + 1.0;
	}

	dist_wall = ray->proj;
	dist_player = 0.0;

	if (ray->max_h < 0)
		ray->max_h = SCREEN_HEIGHT;
	y = 0;
	while (y < ray->max_h - 1)
	{
		current_dist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
		weight = (current_dist - dist_player) / (dist_wall - dist_player);
		current_floor = get_vect(weight * floor_wpos.x + (1.0 - weight)
				* data->player.index.x, weight * floor_wpos.y + (1.0 - weight)
				* data->player.index.y, 0);
		text_pos = get_vect((int)(current_floor.x * data->texture_celling.width)
				% data->texture_celling.width, (int)(current_floor.y
					* data->texture_celling.height)
				% data->texture_celling.height, 0);

		y++;
	}
}