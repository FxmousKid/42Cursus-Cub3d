/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:08 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/03 02:49:45 by theo             ###   ########.fr       */
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

/* UTILS */
long int	get_current_time(void);

/* MAP */
void		draw_map(t_data *data);
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
int			look_right(t_data *data);
int			look_left(t_data *data);
void		rotate_camera(t_data *data, double angle);

/* RAYCASTING */
void		raycasting(t_data *data);
t_vect		init_length(t_vect *ray);
void		cast_ray(t_data *data, t_ray *ray);
void		dda_algo(t_data *data, t_ray *ray, t_vect *map_pos);
void		draw_wall(t_data *data, t_ray *ray);

/* TEXTURE */
int			get_side_texture(t_ray *ray);

#endif
