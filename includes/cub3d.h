/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:08 by inazaria          #+#    #+#             */
/*   Updated: 2025/01/26 19:51:04 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <unistd.h>

# include "../mlx_linux/mlx.h"
# include "../libft/includes/libft.h"
# include "error_manager.h"

# define RED_TXT		"\e[0;31m"
# define GREEN_TXT		"\e[0;32m"
# define YELLOW_TXT		"\e[0;33m"
# define BLUE_TXT		"\e[0;34m"
# define PURPLE_TXT		"\e[0;35m"
# define CYAN_TXT		"\e[0;36m"
# define GREY_TXT		"\e[0;37m"
# define WHITE_TXT		"\e[0;39m"
# define BOLD_TXT		"\e[1m"
# define UNDERLINE_TXT	"\e[4m"
# define REVERSE_TXT	"\e[7m"
# define HIDDEN_TXT		"\e[8m"
# define END_TXT		"\e[0m"

# define WHITE_ARGB 0x00FFFFFF
# define RED_ARGB	0x00FF0000
# define GREEN_ARGB	0x0000FF00
# define BLUE_ARGB	0x000000FF
# define COLOR_MAX  0xFFFFFFFF
# define GREY_ARGB  0x80808080

# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720

# define MAX_SIZE_MAP 200

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
}				t_pos;

typedef struct s_tile
{
	char	type;
	t_pos	pos;
}				t_tile;

typedef struct s_player
{
	t_pos	direction;
	t_pos	pos;
}				t_player;

typedef struct s_pixel
{
	void	*pixel;
	char	*addr;
	int		bits;
	int		length;
	int		endian;
}				t_pixel;

typedef struct s_img
{
	void	*addr;
	int		width;
	int		height;
}				t_img;

typedef struct s_texture
{
	t_img	n_texture;
	t_img	s_texture;
	t_img	w_texture;
	t_img	e_texture;
	t_img	f_texture;
	t_img	c_texture;
	int		f_color;
	int		c_color;
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			size;
	int			height_map;
	t_player	player;
	t_pos		center_pos;
	t_tile		map[MAX_SIZE_MAP][MAX_SIZE_MAP];
	t_texture	texture;
	t_pixel		pixel;
}				t_data;

/* PIXEL */
int		init_pixel(t_pixel *pixel, void *mlx);
void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
void	put_pixel(t_data *data, int x, int y, int color);

/* RENDER */
int		render_next_frame(t_data *data);
void	render_loop(t_data *data);

/* FIGURE */
void	draw_line(t_data *data, t_pos pos0, t_pos pos1, int color);
void	draw_square(t_data *data, t_pos top_left, int color);
void	fill_square(t_data *data, t_pos top_left, int color);
void	draw_circle(t_data *data, t_pos pos, int rayon, int color);

/* PARSING */
int		check_file_name(char *file);
int		parsing_map(t_data *data, char *file_map);
int		parse_file(t_data *data, int fd);
int		get_texture(t_data *data, int fd);
int		fill_map(t_data *data, int fd);

/* MAP */
void	print_map(t_data *data);
void	draw_map(t_data *data);

/* CLOSE */
int	close_window(t_data *data);

/* KEY */
int	key_listener(int keycode, t_data *data);

#endif
