/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:52:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/09 23:30:27 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flashlight_shader(t_data *data, t_vect pos, int color, double dist)
{
	int		a;
	int		r;
	int		g;
	int		b;
	double	brightness;

	(void)pos;
	(void)dist;
	if (data->movement.flash == false)
		return (color);
	brightness = (100 / ((fabs(pos.x - SCREEN_WIDTH / 2) + 1) + (fabs(pos.y
						- SCREEN_HEIGHT / 2)))) / (dist * 2) * 50;
	if (brightness < 1)
		brightness = 1;
	if (brightness > 10)
		brightness = 10;
	a = ((color >> 24) & 0xff);
	r = ((double)((color >> 16) & 0xff)) * brightness;
	if (r > 255)
		r = 255;
	g = ((double)((color >> 8) & 0xff)) * brightness;
	if (g > 255)
		g = 255;
	b = ((double)((color)&0xff)) * brightness;
	if (b > 255)
		b = 255;
	return ((a << 24) + (r << 16) + (g << 8) + (b));
}
