/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionlistener.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:35:28 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 16:57:21 by ptheo            ###   ########.fr       */
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