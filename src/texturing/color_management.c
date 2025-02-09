/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:59:37 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/09 23:01:39 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_argb	hex_to_argb(int color)
{
	t_argb	argb;

	argb.alpha = (color >> 24) & 0xff;
	argb.red = ((color >> 16) & 0xff);
	argb.green = ((color >> 8) & 0xff);
	argb.blue = ((color)&0xff);
	return (argb);
}

int	argb_to_hex(t_argb argb)
{
	return ((argb.alpha << 24) + (argb.red << 16) + (argb.green << 8)
		+ (argb.blue));
}
