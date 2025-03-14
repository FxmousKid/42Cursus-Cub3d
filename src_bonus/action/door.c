/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:43:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/10 19:59:50 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_data *data)
{
	t_vect	pos;
	t_vect	dir;

	pos = data->player.index;
	dir = data->player.direction;
	if (data->map[(int)(pos.y + dir.y)][(int)(pos.x - dir.x)].type == '2')
	{
		if (data->map[(int)(pos.y + dir.y)][(int)(pos.x - dir.x)].door.open)
		{
			data->map[(int)(pos.y + dir.y)][(int)(pos.x
					- dir.x)].door.open = false;
		}
		else
		{
			data->map[(int)(pos.y + dir.y)][(int)(pos.x
					- dir.x)].door.open = true;
		}
	}
}
