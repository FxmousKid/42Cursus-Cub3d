/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:21:04 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/06 10:24:59 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_lines_for_circle(t_data *data, t_vect pos, int x_y[2], int color)
{
	draw_line(data, pos, get_vect(x_y[0] + pos.x, x_y[1] + pos.y, 0), color);
	draw_line(data, pos, get_vect(x_y[0] + pos.x, x_y[1] + pos.y, 0), color);
	draw_line(data, pos, get_vect(x_y[1] + pos.x, x_y[0] + pos.y, 0), color);
	draw_line(data, pos, get_vect(-x_y[0] + pos.x, x_y[1] + pos.y, 0), color);
	draw_line(data, pos, get_vect(-x_y[1] + pos.x, x_y[0] + pos.y, 0), color);
	draw_line(data, pos, get_vect(x_y[0] + pos.x, -x_y[1] + pos.y, 0), color);
	draw_line(data, pos, get_vect(x_y[1] + pos.x, -x_y[0] + pos.y, 0), color);
	draw_line(data, pos, get_vect(-x_y[0] + pos.x, -x_y[1] + pos.y, 0), color);
	draw_line(data, pos, get_vect(-x_y[1] + pos.x, -x_y[0] + pos.y, 0), color);
}
