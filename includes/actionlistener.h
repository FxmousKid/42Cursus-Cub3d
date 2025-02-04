/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionlistener.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:35:28 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/04 01:42:21 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONLISTENER_H
# define ACTIONLISTENER_H

# include "struct.h"

int	key_pressed(int keycode, t_data *data);
int	close_window(t_data *data);
int	key_released(int keycode, t_data *data);
int	mouse_motion(int x, int y, t_data *data);

#endif