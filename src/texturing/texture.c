/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:23:28 by theo              #+#    #+#             */
/*   Updated: 2025/02/04 12:03:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	get_texture(t_data *data, char *path)
{
	t_img	img;

	path = ft_strtrim(path, "\n");
	img.img = mlx_xpm_file_to_image(data->mlx, path, &img.width, &img.height);
	img.pixels = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_size,
			&img.endian);
	return (img);
}

t_img	*get_side_texture(t_data *data, t_ray *ray)
{
	if (ray->w_side == 0)
	{
		if (ray->step.x == -1)
		{
			return (&data->texture_west);
		}
		return (&data->texture_east);
	}
	if (ray->step.y == -1)
	{
		return (&data->texture_south);
	}
	return (&data->texture_north);
}

void	draw_texture(t_data *data, t_img *texture, t_ray *ray)
{
	unsigned int	color;
	int				y;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				pos_x;
	int				pos_y;

	if (ray->w_side == 0)
		wall_x = data->player.index.y + ray->proj * ray->ray.y;
	else
		wall_x = data->player.index.x + ray->proj * ray->ray.x;
	wall_x -= floor((wall_x));
	pos_x = (int)(wall_x * (double)(texture->width));
	if (ray->w_side == 0 && ray->ray.x < 0)
		pos_x = texture->width - pos_x - 1;
	if (ray->w_side == 1 && ray->ray.y < 0)
		pos_x = texture->width - pos_x - 1;
	step = 1.0 * (texture->height / ray->line_h);
	tex_pos = (ray->min_h - SCREEN_HEIGHT / 2 + ray->line_h / 2) * step;
	y = ray->min_h;
	while (y < ray->max_h)
	{
		pos_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		if (texture->endian == 0)
		{
			color = pos_y * texture->line_size + pos_x
				* (texture->bits_per_pixel / 8);
		}
		put_pixel(data, ray->index, y, *(int *)(texture->pixels + color));
		y++;
	}
}
