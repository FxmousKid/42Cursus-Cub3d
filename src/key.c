/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:50:23 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/27 04:04:04 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_listener(int keycode, t_data *data)
{
	ft_printf("key touch : %d\n", keycode);
	if (keycode == K_W)
	{
		move_front(data);
		ft_printf("touch W\n");
	}
	if (keycode == K_S)
	{
		move_back(data);
		ft_printf("touch S\n");
	}
	if (keycode == K_A)
	{
		look_left(data);
		ft_printf("touch A\n");
	}
	if (keycode == K_D)
	{
		look_right(data);
		ft_printf("touch D\n");
	}
	return (0);
}