/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:52:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/11 19:48:15 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dark_color(int color, double dist, int active)
{
	int	dark;
	int	alpha;
	int	red;
	int	blue;
	int	green;

	if (active == 0)
		return (color);
	dark = 100 - (100 * dist) / 10;
	if (dark < 0)
		dark = 0;
	alpha = ((color >> 24) & 0xff);
	red = ((double)((color >> 16) & 0xff) / 100) * dark * 0.1;
	green = ((double)((color >> 8) & 0xff) / 100) * dark * 0.1;
	blue = ((double)(color & 0xff) / 100) * dark * 0.1;
	return ((alpha << 24) + (red << 16) + (green << 8) + (blue));
}

int	apply_shader(t_data *data, t_vect pos, int color, double dist)
{
	if (data->movement.darklight)
		color = dark_color(color, dist, data->movement.darklight);
	color = flashlight_shader(data, pos, color, dist);
	return (color);
}

int	flashlight_shader(t_data *data, t_vect p, int color, double dist)
{
	int		a;
	int		r;
	int		g;
	int		b;
	double	brightness;

	if (data->movement.flash == false)
		return (color);
	brightness = ((100 * SCREEN_WIDTH / 1920) / ((fabs(p.x - SCREEN_WIDTH / 2)
					+ 1) + (fabs(p.y - SCREEN_HEIGHT / 2)))) / (dist * 2) * 50;
	if (brightness < 1)
		brightness = 1;
	if (brightness > 15)
		brightness = 15;
	a = ((color >> 24) & 0xff);
	r = ((double)((color >> 16) & 0xff)) * brightness;
	if (r > 255)
		r = 255;
	g = ((double)((color >> 8) & 0xff)) * brightness;
	if (g > 255)
		g = 255;
	b = ((double)(color & 0xff)) * brightness;
	if (b > 255)
		b = 255;
	return ((a << 24) + (r << 16) + (g << 8) + (b));
}

void	draw_flashlight_image(t_data *data)
{
	unsigned int	color;
	int				x;
	int				y;

	y = -1;
	while (++y < data->flashlight_img.height)
	{
		x = -1;
		while (++x < data->flashlight_img.width)
		{
			color = y * data->flashlight_img.line_size + x
				* (data->flashlight_img.bits_per_pixel / 8);
			if ((*(int *)(data->flashlight_img.pixels
					+ color) & 0x00FFFFFF) != 0)
			{
				if ((int)data->flash_img_pos.y + y < SCREEN_HEIGHT
					&& (int)data->flash_img_pos.x + x < SCREEN_WIDTH)
					data->frame[(int)data->flash_img_pos.y
						+ y][(int)data->flash_img_pos.x
						+ x] = dark_color(*(int *)(data->flashlight_img.pixels
								+ color), 0, data->movement.darklight);
			}
		}
	}
}

void	move_flash_light(t_data *data)
{
	if (data->flash_img_pos.y == SCREEN_HEIGHT - 300)
	{
		data->flash_img_pos.z = -5;
	}
	else if (data->flash_img_pos.y == SCREEN_HEIGHT - 370)
	{
		data->flash_img_pos.z = 5;
	}
	data->flash_img_pos.y += data->flash_img_pos.z;
}
