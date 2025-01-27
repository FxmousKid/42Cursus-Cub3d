/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:13:40 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/27 04:06:28 by theo             ###   ########.fr       */
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

void	draw_square(t_data *data, t_vect top_left, int color)
{
	t_vect	top_right;
	t_vect	bot_left;
	t_vect	bot_right;

	top_right.x = top_left.x + data->size;
	top_right.y = top_left.y;
	bot_left.x = top_left.x;
	bot_left.y = top_left.y + data->size;
	bot_right.x = top_left.x + data->size;
	bot_right.y = top_left.y + data->size;
	draw_line(data, top_left, top_right, color);
	draw_line(data, top_left, bot_left, color);
	draw_line(data, top_right, bot_right, color);
	draw_line(data, bot_left, bot_right, color);
}

void	fill_square(t_data *data, t_vect top_left, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			put_pixel(data, top_left.x + i, top_left.y + j, color);
			j++;
		}
		i++;
	}
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