/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_celling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:55:56 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/11 15:39:14 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_celling_raycasting(t_data *data)
{
	t_floor	*floor;
	int		i;

	i = SCREEN_HEIGHT / 2 + 1;
	while (i < SCREEN_HEIGHT)
	{
		floor = (t_floor *)malloc(sizeof(t_floor) * 1);
		floor->y = i;
		floor->ray_dir0 = get_vect(data->player.direction.x
				- data->player.plane.x, data->player.direction.y
				- data->player.plane.y, 0);
		floor->ray_dir1 = get_vect(data->player.direction.x
				+ data->player.plane.x, data->player.direction.y
				+ data->player.plane.y, 0);
		floor->p = i - SCREEN_HEIGHT / 2;
		floor->posz = 0.5 * SCREEN_HEIGHT;
		draw_floor_celling(data, floor);
		free(floor);
		i++;
	}
}

void	floor_celling_texture(t_data *data, t_floor *side)
{
	side->texture_cor1 = get_vect((int)(((double)data->texture_floor.width
					* (double)(side->floor_pos.x - (int)side->floor_pos.x)))
			% (data->texture_floor.width - 1),
			(int)((double)data->texture_floor.height
				* (double)(side->floor_pos.y - (int)side->floor_pos.y))
			% (data->texture_floor.height - 1), 0);
	side->texture_cor2 = get_vect((int)((double)data->texture_celling.width
				* (side->floor_pos.x - (int)side->floor_pos.x))
			% (data->texture_celling.width - 1),
			(int)((double)data->texture_celling.height * (side->floor_pos.y
					- (int)side->floor_pos.y)) % (data->texture_celling.height
				- 1), 0);
}

void	draw_texture_floor_celling(t_data *data, t_floor *side, int i,
		double dist_p)
{
	unsigned int	color;

	if (side->texture_cor1.x >= 0
		&& side->texture_cor1.x <= data->texture_floor.width
		&& side->texture_cor1.y >= 0
		&& side->texture_cor1.y <= data->texture_floor.height)
	{
		color = side->texture_cor1.y * data->texture_floor.line_size
			+ side->texture_cor1.x * (data->texture_floor.bits_per_pixel / 8);
		data->frame[side->y][i] = apply_shader(data, get_vect(i, side->y, 0),
				*(int *)(data->texture_floor.pixels + color), dist_p);
	}
	if (side->texture_cor2.x >= 0
		&& side->texture_cor2.x <= data->texture_celling.width
		&& side->texture_cor2.y >= 0
		&& side->texture_cor2.y <= data->texture_celling.height)
	{
		color = side->texture_cor2.y * data->texture_celling.line_size
			+ side->texture_cor2.x * (data->texture_celling.bits_per_pixel / 8);
		data->frame[(SCREEN_HEIGHT - side->y)][i] = apply_shader(data,
				get_vect(i, SCREEN_HEIGHT - side->y - 1, 0),
				*(int *)(data->texture_celling.pixels + color), dist_p);
	}
}

void	draw_floor_celling(t_data *data, t_floor *side)
{
	float	row;
	int		i;
	double	dist_p;

	i = 0;
	row = side->posz / side->p;
	side->floor_step = get_vect(row * (side->ray_dir0.x - side->ray_dir1.x)
			/ SCREEN_WIDTH, row * (side->ray_dir1.y - side->ray_dir0.y)
			/ SCREEN_WIDTH, 0);
	side->floor_pos = get_vect(data->player.index.x - row * side->ray_dir0.x,
			data->player.index.y + row * side->ray_dir0.y, 0);
	while (i < SCREEN_WIDTH)
	{
		floor_celling_texture(data, side);
		dist_p = sqrt((fabs(data->player.index.x - side->floor_pos.x)
					* fabs(data->player.index.x - side->floor_pos.x)
					+ fabs(data->player.index.y - side->floor_pos.y)
					* fabs(data->player.index.y - side->floor_pos.y)));
		side->floor_pos.x += side->floor_step.x;
		side->floor_pos.y += side->floor_step.y;
		draw_texture_floor_celling(data, side, i, dist_p);
		i++;
	}
}
