/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:25:20 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/31 17:18:40 by theo             ###   ########.fr       */
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
	double		height;
	t_vect		index;
	t_vect		pos;
}				t_tile;

typedef struct s_player
{
	int			speed;
	double		camera_speed;
	double		angle;
	t_vect		plane;
	t_vect		direction;
	t_vect		pos;
	t_vect		index;
}				t_player;

typedef struct s_loop
{
	int			fps;
	double		interval;
	long int	last_time;
	double		delta;
}				t_loop;

typedef struct s_ray
{
	int			w_side;
	int			index;
	double		angle;
	t_vect		ray;
	t_vect		side;
	t_vect		delta;
	t_vect		step;
	t_tile		wall;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			map_height;
	double		size;
	double		fov;
	t_player	player;
	t_pixel		pixel;
	t_loop		loop;
	t_move		movement;
	t_tile		map[MAP_SIZE_MAX][MAP_SIZE_MAX];
}				t_data;

#endif