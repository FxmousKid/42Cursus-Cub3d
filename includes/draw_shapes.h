/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:40:28 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/11 15:13:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SHAPES_H
# define DRAW_SHAPES_H

# include "struct.h"

/* SHAPES */
void		draw_line(t_data *data, t_vect pos0, t_vect pos1, int color);
void		draw_square(t_data *data, t_square square, int color);
void		draw_circle(t_data *data, t_vect pos, int rayon, int color);

/* VECTOR */
t_vect		get_vect(double x, double y, double z);
t_square	get_square(t_vect v1, t_vect v2, t_vect v3, t_vect v4);

/* PIXEL */
int			init_pixel(t_pixel *pixel, void *mlx);
void		my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
void		put_pixel(t_data *data, int x, int y, int color);

#endif
