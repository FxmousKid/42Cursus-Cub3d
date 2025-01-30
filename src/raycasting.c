/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:01:54 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 01:12:08 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_ray(t_data *data)
{
	double	last_angle;
	double	angle;
	int		i;

	i = 0;
	angle = data->player.angle - PI / 4;
	last_angle = data->player.angle + PI / 4;
	while (i < SCREEN_WIDTH && angle <= last_angle)
	{
		data->ray[i].angle = angle;
		data->ray[i].distance = 100;
		angle += 0.5;
		i++;
	}
	data->ray[i].angle = -1;
	return (0);
}

double	cast_ray(t_data *data, double angle)
{
	double	step;
	double	t_x;
	double	t_y;
	double	s_y;
	double	s_x;

	step = 1;
	(void)angle;
	s_y = ((int)data->player.index.y % data->size);
	s_x = ((int)data->player.index.x % data->size);
	t_x = data->player.pos.x;
	t_y = data->player.pos.y;
	while (step < 5)
	{
		t_x += s_x;
		t_y += s_y;
		draw_circle(data, get_vect(t_x, t_y, 0), 5, RED_ARGB);
		s_y = ((int)data->player.index.y % data->size);
		s_x = ((int)data->player.index.x % data->size);
		step++;
	}
	return (step);
}

void	raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (data->ray[i].angle != -1 && i < SCREEN_WIDTH)
	{
		/// if (i == 0 || data->ray[i + 1].angle == -1)
		//{
		cast_ray(data, data->ray[i].angle);
		draw_line(data, data->player.pos, get_vect(data->player.pos.x
				+ cos(data->ray[i].angle) * data->ray[i].distance,
				data->player.pos.y + sin(data->ray[i].angle)
				* data->ray[i].distance, 0), RED_ARGB);
		//}
		i++;
	}
}
