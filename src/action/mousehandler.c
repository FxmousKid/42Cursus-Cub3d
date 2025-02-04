/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:38:03 by theo              #+#    #+#             */
/*   Updated: 2025/02/04 01:59:15 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_motion(int x, int y, t_data *data)
{
	(void)y;
	if (data->last_pos_mouse - x > 0 || x <= 0)
		look_left(data);
	else if (data->last_pos_mouse - x < 0 || x >= SCREEN_WIDTH - 1)
		look_right(data);
	data->last_pos_mouse = x;
	return (0);
}
