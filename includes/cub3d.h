/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:08 by inazaria          #+#    #+#             */
/*   Updated: 2025/01/28 19:48:56 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include "error_manager.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define PI 3.14159265359

# define RED_TXT "\e[0;31m"
# define GREEN_TXT "\e[0;32m"
# define YELLOW_TXT "\e[0;33m"
# define BLUE_TXT "\e[0;34m"
# define PURPLE_TXT "\e[0;35m"
# define CYAN_TXT "\e[0;36m"
# define GREY_TXT "\e[0;37m"
# define WHITE_TXT "\e[0;39m"
# define BOLD_TXT "\e[1m"
# define UNDERLINE_TXT "\e[4m"
# define REVERSE_TXT "\e[7m"
# define HIDDEN_TXT "\e[8m"
# define END_TXT "\e[0m"

# define WHITE_ARGB 0x00FFFFFF
# define BLACK_ARGB 0x00000000
# define RED_ARGB 0x00FF0000
# define GREEN_ARGB 0x0000FF00
# define BLUE_ARGB 0x000000FF
# define COLOR_MAX 0xFFFFFFFF
# define GREY_ARGB 0x80808080

# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720

# define MAX_SIZE_MAP 200

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct s_tile
{
	char		type;
	double		distance;
	t_vect		top_left;
	t_vect		top_right;
	t_vect		bot_left;
	t_vect		bot_right;
}				t_tile;

typedef struct s_player
{
	int			speed;
	double		camera_speed;
	double		angle;
	double		fov;
	t_vect		direction;
	t_vect		pos;
}				t_player;

typedef struct s_ray
{
	double		angle;
	double		hauteur;
	double		distance;
	t_tile		wall;
}				t_ray;

typedef struct s_pixel
{
	void		*pixel;
	char		*addr;
	int			bits;
	int			length;
	int			endian;
}				t_pixel;

typedef struct s_img
{
	void		*addr;
	int			width;
	int			height;
}				t_img;

typedef struct s_texture
{
	t_img		n_texture;
	t_img		s_texture;
	t_img		w_texture;
	t_img		e_texture;
	t_img		f_texture;
	t_img		c_texture;
	int			f_color;
	int			c_color;
}				t_texture;

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

typedef struct s_loop
{
	int			fps;
	double		interval;
	long int	last_time;
	double		delta;
}				t_loop;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			size;
	int			height_map;
	t_player	player;
	t_loop		loop;
	t_vect		center_pos;
	t_move		movement;
	t_ray		ray[SCREEN_WIDTH];
	t_tile		map[MAX_SIZE_MAP][MAX_SIZE_MAP];
	t_texture	texture;
	t_pixel		pixel;
}				t_data;

/* PIXEL */
int				init_pixel(t_pixel *pixel, void *mlx);
void			my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
void			put_pixel(t_data *data, int x, int y, int color);

/* RENDER */
int				render_next_frame(t_data *data);
void			render_loop(t_data *data);

/* FIGURE */
void			draw_line(t_data *data, t_vect pos0, t_vect pos1, int color);
void			draw_square(t_data *data, t_tile square, int color);
void			fill_square(t_data *data, t_tile square, int color);
void			draw_circle(t_data *data, t_vect pos, int rayon, int color);
t_vect			get_vect(double x, double y, double z);

/* PARSING */
int				check_file_name(char *file);
int				parsing_map(t_data *data, char *file_map);
int				parse_file(t_data *data, int fd);
int				get_texture(t_data *data, int fd);
int				fill_map(t_data *data, int fd);

/* MAP */
void			print_map(t_data *data);
void			draw_map(t_data *data);
void			init_map(t_data *data);
t_tile			focus_middle(t_data *data, t_tile tile);

/* CLOSE */
int				close_window(t_data *data);

/* KEY */
int				key_pressed(int keycode, t_data *data);
int				key_released(int keycode, t_data *data);

/* PLAYER */
void			draw_player(t_data *data);
int				init_player(t_data *data);

/* PLAYER MOVEMENT */
int				key_movement(t_data *data);
int				move_front(t_data *data);
int				move_back(t_data *data);
int				move_right(t_data *data);
int				move_left(t_data *data);

/* CAMERA MOVEMENT */
int				camera_movement(t_data *data);
int				look_right(t_data *data);
int				look_left(t_data *data);
int				look_up(t_data *data);
int				look_down(t_data *data);

/* ROTATION */
t_vect			rotation_yaw(t_data *data, t_vect pos, double angle);
void			applie_rotation(t_data *data, double angle);

/* BACKGROUND */
void			draw_background(t_data *data);

/* UTILS */
long int		get_current_time(void);

/* COLLISION */
bool			can_place(t_data *data);

/* RAYCASTING */
int				init_ray(t_data *data);
void			raycasting(t_data *data);

#endif
