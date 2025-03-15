/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:08 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/15 23:29:19 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "actionlistener.h"
# include "dependencies.h"
# include "draw_shapes.h"
# include "error_manager.h"
# include "macro.h"
# include "parser.h"
# include "struct.h"

/* DATA */
int			init_data(t_data *data, char *argv[]);

/* RENDERING */
void		render_loop(t_data *data);
int			render_next_frame(t_data *data);
void		draw_background(t_data *data);
void		draw_frame(t_data *data);
/* UTILS */
long int	get_current_time(void);
void		free_tab(void **tab, size_t size);
size_t		len_tab(void **t);

/* MAP */
void		draw_map(t_data *data);
void		draw_square_map(t_data *data, int x, int y);
void		print_map(t_data *data);

/* PLAYER */
int			init_player(t_data *data);
void		draw_player(t_data *data);
void		player_update(t_data *data);
void		first_view_player(t_data *data, char d);

/* PLAYER MOVE */
int			player_movement(t_data *data);
int			move_front(t_data *data);
int			move_back(t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);

/* CAMERA MOVE */
int			camera_movement(t_data *data);
int			look_right(t_data *data, double speed);
int			look_left(t_data *data, double speed);
void		rotate_camera(t_data *data, double angle);

/* RAYCASTING */
void		raycasting(t_data *data);
t_vect		init_length(t_vect *ray);
void		cast_ray(t_data *data, t_ray *ray);
void		dda_algo(t_data *data, t_ray *ray, t_vect *map_pos);
int			dda_algo_check(t_data *data, t_ray *ray, t_vect *map_pos);
void		draw_wall(t_data *data, t_ray *ray);

/* FLOOR CASTING */
void		floor_celling_raycasting(t_data *data);
void		floor_celling_texture(t_data *data, t_floor *side);
void		draw_texture_floor_celling(t_data *data, t_floor *side, int i,
				double dist_p);
void		draw_floor_celling(t_data *data, t_floor *floor);

/* TEXTURE */
t_img		*get_side_texture(t_data *data, t_ray *ray);
void		get_wall_x(t_data *data, t_ray *ray);
int			get_texture(t_data *data, t_img *img, char *p);
void		draw_texture(t_data *data, t_img *texture, t_ray *ray);
int			dark_color(int color, double dist, int active);
int			apply_shader(t_data *data, t_vect pos, int color, double dist);

/* COLOR */
t_argb		hex_to_argb(int color);
int			argb_to_hex(t_argb argb);

/* FLASHLIGHT */
int			flashlight_shader(t_data *data, t_vect pos, int color, double dist);
void		draw_flashlight_image(t_data *data);
void		move_flash_light(t_data *data);

/* DOOR */
void		open_door(t_data *data);

#endif
