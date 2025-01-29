/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:04:46 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/28 16:51:54 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_pixel(t_pixel *pixel, void *mlx)
{
	pixel->pixel = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (pixel->pixel == NULL)
		return (free(pixel), pixel = NULL, -1);
	pixel->addr = mlx_get_data_addr(pixel->pixel, &pixel->bits, &pixel->length,
			&pixel->endian);
	return (0);
}

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = pixel->bits - 8;
	dst = pixel->addr + (y * pixel->length + x * (pixel->bits / 8));
	while (i >= 0)
	{
		if (pixel->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (pixel->bits - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > 0 && y > 0)
		my_mlx_pixel_put(&data->pixel, x, y, color);
}
