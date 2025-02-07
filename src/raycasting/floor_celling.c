/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_celling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:55:56 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/07 19:41:39 by ptheo            ###   ########.fr       */
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

void	draw_floor_celling(t_data *data, t_floor *floor)
{
	t_vect			floor_step;
	t_vect			floor_pos;
	t_vect			texture_cor;
	float			row;
	int				i;
	unsigned int	color;

	i = 0;
	row = floor->posz / floor->p;
	floor_step = get_vect(row * (floor->ray_dir1.x - floor->ray_dir0.x)
			/ SCREEN_WIDTH, row * (floor->ray_dir1.y - floor->ray_dir0.y)
			/ SCREEN_WIDTH, 0);
	floor_pos = get_vect(data->player.index.x + row * floor->ray_dir0.x,
			data->player.index.y + row * floor->ray_dir0.y, 0);
	while (i < SCREEN_WIDTH)
	{
		texture_cor = get_vect((int)(data->texture_floor.width * (floor_pos.x
						- (int)floor_pos.x)) & (data->texture_floor.width - 1),
				(int)(data->texture_floor.height * (floor_pos.y
						- (int)floor_pos.y)) & (data->texture_floor.height - 1),
				0);
		floor_pos.x += floor_step.x;
		floor_pos.y += floor_step.y;
		color = texture_cor.y * data->texture_floor.line_size + texture_cor.x
			* (data->texture_floor.bits_per_pixel / 8);
		put_pixel(data, i, floor->y, *(int *)(data->texture_floor.pixels
				+ color));
		color = texture_cor.y * data->texture_celling.line_size + texture_cor.x
			* (data->texture_celling.bits_per_pixel / 8);
		put_pixel(data, i, SCREEN_HEIGHT - floor->y - 1,
			*(int *)(data->texture_celling.pixels + color));
		i++;
	}
}
