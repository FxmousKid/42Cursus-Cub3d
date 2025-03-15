/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:59:37 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 18:48:10 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_argb	hex_to_argb(int color)
{
	t_argb	argb;

	argb.alpha = (color >> 24) & 0xff;
	argb.red = ((color >> 16) & 0xff);
	argb.green = ((color >> 8) & 0xff);
	argb.blue = ((color) & 0xff);
	return (argb);
}

int	argb_to_hex(t_argb argb)
{
	return ((argb.alpha << 24) + (argb.red << 16) + (argb.green << 8)
		+ (argb.blue));
}

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
