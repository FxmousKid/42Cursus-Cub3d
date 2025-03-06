/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:52:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/06 10:10:37 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	b = ((double)((color) & 0xff)) * brightness;
	if (b > 255)
		b = 255;
	return ((a << 24) + (r << 16) + (g << 8) + (b));
}
