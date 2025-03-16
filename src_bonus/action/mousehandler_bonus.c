/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:38:03 by theo              #+#    #+#             */
/*   Updated: 2025/03/15 16:36:11 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_motion(int x, int y, t_data *data)
{
	(void)y;
	if (SCREEN_WIDTH / 2 - x > 0)
		look_left(data, (SCREEN_WIDTH / 2 - x) * (data->player.camera_speed
				/ 70));
	else if (SCREEN_WIDTH / 2 - x < 0)
		look_right(data, -(SCREEN_WIDTH / 2 - x) * (data->player.camera_speed
				/ 70));
	mlx_mouse_move(data->mlx, data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	return (0);
}
