/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:25:20 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/04 03:58:00 by theo             ###   ########.fr       */
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
	double		speed;
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

typedef struct s_img
{
	void		*img;
	char		*pixels;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_ray
{
	int			w_side;
	int			index;
	double		angle;
	int			line_h;
	int			max_h;
	int			min_h;
	double		proj;
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
	int			last_pos_mouse;
	double		size;
	double		fov;
	t_player	player;
	t_pixel		pixel;
	t_loop		loop;
	t_move		movement;
	t_tile		map[MAP_SIZE_MAX][MAP_SIZE_MAX];
	t_img		texture_north;
	t_img		texture_south;
	t_img		texture_west;
	t_img		texture_east;
	t_img		texture_floor;
	t_img		texture_celling;
}				t_data;

#endif