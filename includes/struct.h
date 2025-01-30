/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:25:20 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 19:38:36 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "macro.h"
# include <stdbool.h>

typedef struct s_move
{
	bool		front;
	bool		back;
	bool		left;
	bool		right;
	bool		look_left;
	bool		look_right;
	bool		look_up;
	bool		look_down;
}				t_move;

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct s_square
{
	t_vect		top_left;
	t_vect		top_right;
	t_vect		bot_left;
	t_vect		bot_right;
}				t_square;

typedef struct s_pixel
{
	void		*pixel;
	char		*addr;
	int			bits;
	int			length;
	int			endian;
}				t_pixel;

typedef struct s_tile
{
	char		type;
	t_vect		pos;
}				t_tile;

typedef struct s_loop
{
	int			fps;
	double		interval;
	long int	last_time;
	double		delta;
}				t_loop;

typedef struct s_ray
{
	double		angle;
	t_tile		wall;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			map_height;
	int			size;
	t_pixel		pixel;
	t_loop		loop;
	t_move		movement;
	t_tile		map[MAP_SIZE_MAX][MAP_SIZE_MAX];
}				t_data;

#endif