/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:34:35 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 17:34:56 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keycode, t_data *data)
{
	ft_printf("key pressed : %d\n", keycode);
	if (keycode == XK_w)
	{
		data->movement.front = true;
	}
	if (keycode == XK_s)
	{
		data->movement.back = true;
	}
	if (keycode == XK_a)
	{
		data->movement.left = true;
	}
	if (keycode == XK_d)
	{
		data->movement.right = true;
	}
	if (keycode == XK_Left)
	{
		data->movement.look_left = true;
	}
	if (keycode == XK_Right)
	{
		data->movement.look_right = true;
	}
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	ft_printf("key released : %d\n", keycode);
	if (keycode == XK_w)
	{
		data->movement.front = false;
	}
	if (keycode == XK_s)
	{
		data->movement.back = false;
	}
	if (keycode == XK_a)
	{
		data->movement.left = false;
	}
	if (keycode == XK_d)
	{
		data->movement.right = false;
	}
	if (keycode == XK_Left)
	{
		data->movement.look_left = false;
	}
	if (keycode == XK_Right)
	{
		data->movement.look_right = false;
	}
	return (0);
}
