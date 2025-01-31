/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:53:33 by theo              #+#    #+#             */
/*   Updated: 2025/01/31 03:02:11 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	touch_player(t_data *data)
{
	t_vect pos;

	pos = get_vect(data->player.pos.x / data->size, data->player.pos.y
			/ data->size, 0);
	if (data->map[(int)pos.y][(int)pos.x].type == '1')
		return (true);
	return (false);
}