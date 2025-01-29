/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:19:36 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/28 17:17:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	can_place(t_data *data)
{
	t_tile	current;
	int		x;
	int		y;
	double	distance;

	y = 0;
	while (y < data->height_map)
	{
		x = 0;
		while (data->map[y][x].type != '\0')
		{
			if (data->map[y][x].type == '1')
			{
				current = data->map[y][x];
				distance = sqrt(pow(fabs((current.top_left.x
									+ current.bot_right.x) / 2), 2)
						+ pow(fabs((current.top_left.y + current.bot_right.y)
								/ 2), 2));
				if (distance <= data->size / 2 + data->size / 3)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
