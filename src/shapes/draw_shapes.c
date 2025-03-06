/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:39:24 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/06 14:06:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"

void	draw_line(t_data *data, t_vect pos0, t_vect pos1, int color)
{
	double	x;
	double	y;
	int		n;
	double	max;

	n = 0;
	x = pos1.x - pos0.x;
	y = pos1.y - pos0.y;
	max = sqrt(x * x + y * y);
	if (max > 0)
	{
		x /= max;
		y /= max;
	}
	while (n <= max)
	{
		put_pixel(data, pos0.x, pos0.y, color);
		pos0.x += x;
		pos0.y += y;
		n++;
	}
}

void	draw_square(t_data *data, t_square square, int color)
{
	draw_line(data, square.top_left, square.top_right, color);
	draw_line(data, square.top_left, square.bot_left, color);
	draw_line(data, square.top_right, square.bot_right, color);
	draw_line(data, square.bot_left, square.bot_right, color);
}

void	fill_half_square(t_data *data, t_vect positions[3], int color)
{
	double	x;
	double	y;
	int		n;
	double	max;

	n = 0;
	x = positions[1].x - positions[0].x;
	y = positions[1].y - positions[0].y;
	max = sqrt(x * x + y * y);
	if (max > 0)
	{
		x /= max;
		y /= max;
	}
	while (n <= max)
	{
		draw_line(data, positions[0], positions[2], color);
		positions[0].x += x;
		positions[0].y += y;
		n++;
	}
}

void	fill_square(t_data *data, t_square square, int color)
{
	t_vect	positions[3];

	positions[0] = square.top_right;
	positions[1] = square.bot_left;
	positions[2] = square.top_right;
	fill_half_square(data, positions, color);
	positions[0] = square.bot_left;
	fill_half_square(data, positions, color);
}

void	draw_lines_for_circle(t_data *data, t_vect pos, int x_y[2], int color);
						   
void	draw_circle(t_data *data, t_vect pos, int rayon, int color)
{
	int	d;

	int x_y[2];
	x_y[0] = 0;
	x_y[1] = rayon;
	d = 5 - 4 * rayon;
	while (x_y[0] <= x_y[1])
	{
		draw_lines_for_circle(data, pos, x_y, color);
		if (d > 0)
		{
			x_y[1]--;
			d = d - 8 * x_y[1];
		}
		else
		{
			x_y[0]++;
			d = d + 8 * x_y[0] + 4;
		}
	}
}
