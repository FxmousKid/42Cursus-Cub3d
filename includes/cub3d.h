/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:08 by inazaria          #+#    #+#             */
/*   Updated: 2025/01/30 19:42:56 by ptheo            ###   ########.fr       */
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
int			init_data(t_data *data);

/* RENDERING */
void		render_loop(t_data *data);
int			render_next_frame(t_data *data);

/* UTILS */
long int	get_current_time(void);

/* MAP */
void		draw_map(t_data *data);
void		print_map(t_data *data);

#endif
