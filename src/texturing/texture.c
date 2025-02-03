/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:23:28 by theo              #+#    #+#             */
/*   Updated: 2025/02/03 02:27:00 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_side_texture(t_ray *ray)
{
	if (ray->w_side == 0)
	{
		if (ray->step.x == -1)
		{
			return (YELLOW_ARGB);
		}
		return (RED_ARGB);
	}
	if (ray->step.y == -1)
	{
		return (BLUE_ARGB);
	}
	return (GREEN_ARGB);
}
