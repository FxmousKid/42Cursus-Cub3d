/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:13:40 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/28 04:44:01 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect	get_vect(double x, double y, double z)
{
	t_vect	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

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

void	draw_square(t_data *data, t_tile square, int color)
{
	draw_line(data, square.top_left, square.top_right, color);
	draw_line(data, square.top_left, square.bot_left, color);
	draw_line(data, square.top_right, square.bot_right, color);
	draw_line(data, square.bot_left, square.bot_right, color);
}

void	fill_half_square(t_data *data, t_vect pos0, t_vect pos1, t_vect pos3, int color)
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
		draw_line(data, pos0, pos3, color);
		pos0.x += x;
		pos0.y += y;
		n++;
	}
}

void	fill_square(t_data *data, t_tile square, int color)
{
	fill_half_square(data, square.top_left, square.bot_left, square.top_right, color);
	fill_half_square(data, square.bot_right, square.bot_left, square.top_right, color);
}

void	draw_circle(t_data *data, t_vect pos, int rayon, int color)
{
	int		x;
	int		y;
	int		d;

	x = 0;
	y = rayon;
	d = 5 - 4 * rayon;
	while (x <= y)
	{
		draw_line(data, pos, get_vect(x + pos.x, y + pos.y, 0), color);
		draw_line(data, pos, get_vect(x + pos.x, y + pos.y, 0), color);
		draw_line(data, pos, get_vect(y + pos.x, x + pos.y, 0), color);
		draw_line(data, pos, get_vect(-x + pos.x, y + pos.y, 0), color);
		draw_line(data, pos, get_vect(-y + pos.x, x + pos.y, 0), color);
		draw_line(data, pos, get_vect(x + pos.x, -y + pos.y, 0), color);
		draw_line(data, pos, get_vect(y + pos.x, -x + pos.y, 0), color);
		draw_line(data, pos, get_vect(-x + pos.x, -y + pos.y, 0), color);
		draw_line(data, pos, get_vect(-y + pos.x, -x + pos.y, 0), color);
		if (d > 0)
		{
			y--;
			d = d - 8 * y;
		}
		else
		{
			x++;
			d = d + 8 * x + 4;
		}
	}
}