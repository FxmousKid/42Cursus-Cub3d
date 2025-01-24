/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:13:40 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/24 21:42:31 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line(t_data *data, t_pos pos0, t_pos pos1)
{
	double	x;
	double	y;
	int		n;
	double	max;

	n = 0;
	x = pos1.x - pos0.x;
	y = pos1.y - pos0.y;
	max = sqrt(x * x + y * y);
	if (max > 0)
	{
		x /= max;
		y /= max;
	}
	while (n <= max)
	{
		put_pixel(data, pos0.x, pos0.y, WHITE_ARGB);
		pos0.x += x;
		pos0.y += y;
		n++;
	}
}

void	put_square(t_data *data, t_pos top_left)
{
	t_pos	top_right;
	t_pos	bot_left;
	t_pos	bot_right;

	top_right.x = top_left.x + data->size;
	top_right.y = top_left.y;
	bot_left.x = top_left.x;
	bot_left.y = top_left.y + data->size;
	bot_right.x = top_left.x + data->size;
	bot_right.y = top_left.y + data->size;
	put_line(data, top_left, top_right);
	put_line(data, top_left, bot_left);
	put_line(data, top_right, bot_right);
	put_line(data, bot_left, bot_right);
}