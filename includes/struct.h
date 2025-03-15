/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:25:20 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 15:52:14 by ptheo            ###   ########.fr       */
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
	bool		flash;
	bool		darklight;
}				t_move;

typedef struct s_argb
{
	int			alpha;
	int			red;
	int			green;
	int			blue;
}				t_argb;

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

typedef struct s_door
{
	bool		open;
	int			timer;
}				t_door;

typedef struct s_tile
{
	char		type;
	double		height;
	t_door		door;
	t_vect		index;
	t_vect		pos;
}				t_tile;

typedef struct s_enemi
{
	t_vect		pos;
	int			health;
}				t_enemi;

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
	int			ups;
	double		interval_frame;
	double		interval_update;
	long int	last_time;
	double		delta_frame;
	double		delta_update;

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

typedef struct s_floor
{
	t_vect		ray_dir0;
	t_vect		ray_dir1;
	t_vect		floor_step;
	t_vect		floor_pos;
	t_vect		texture_cor1;
	t_vect		texture_cor2;
	int			p;
	int			y;
	float		posz;
	float		row_distance;
}				t_floor;

typedef struct s_ray
{
	int			w_side;
	int			index;
	double		angle;
	int			line_h;
	int			max_h;
	int			min_h;
	double		proj;
	double		wall_x;
	bool		is_door;
	t_door		door;
	t_vect		map_pos;
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
	int			**frame;
	bool		no_door;
	t_player	player;
	t_pixel		pixel;
	t_loop		loop;
	t_move		movement;
	t_tile		**map;
	t_img		texture_north;
	t_img		texture_south;
	t_img		texture_west;
	t_img		texture_east;
	t_img		texture_celling;
	t_img		texture_floor;
	t_img		texture_door;
	t_img		flashlight_img;
	t_vect		flash_img_pos;
}				t_data;

#endif