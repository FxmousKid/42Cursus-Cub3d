/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:34:35 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 15:54:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed_utils(int keycode, t_data *data)
{
	if (keycode == XK_Left)
		data->movement.look_left = true;
	if (keycode == XK_Right)
		data->movement.look_right = true;
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_f)
	{
		if (data->movement.flash == false)
			data->movement.flash = true;
		else
			data->movement.flash = false;
	}
	if (keycode == XK_e)
		open_door(data);
	if (keycode == XK_l)
	{
		if (data->movement.darklight == false)
			data->movement.darklight = true;
		else
			data->movement.darklight = false;
	}
	return (0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->movement.front = true;
	if (keycode == XK_s)
		data->movement.back = true;
	if (keycode == XK_a)
		data->movement.left = true;
	if (keycode == XK_d)
		data->movement.right = true;
	if (keycode == XK_Shift_L)
		data->player.speed *= 2;
	else
		key_pressed_utils(keycode, data);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->movement.front = false;
	if (keycode == XK_s)
		data->movement.back = false;
	if (keycode == XK_a)
		data->movement.left = false;
	if (keycode == XK_d)
		data->movement.right = false;
	if (keycode == XK_Left)
		data->movement.look_left = false;
	if (keycode == XK_Right)
		data->movement.look_right = false;
	if (keycode == XK_Shift_L)
		data->player.speed /= 2;
	return (0);
}
