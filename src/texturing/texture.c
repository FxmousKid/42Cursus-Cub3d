/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:23:28 by theo              #+#    #+#             */
/*   Updated: 2025/02/09 23:30:54 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	get_texture(t_data *data, char *p)
{
	char	*path;
	t_img	img;

	path = ft_strtrim(p, "\n");
	img.img = mlx_xpm_file_to_image(data->mlx, path, &img.width, &img.height);
	img.pixels = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_size,
			&img.endian);
	free(path);
	free(p);
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
		wall_x = data->player.index.x - ray->proj * ray->ray.x;
	pos_x = (int)((wall_x - floor(wall_x)) * texture->width);
	step = 1.0 * ((double)texture->height / (double)ray->line_h);
	tex_pos = (ray->min_h - (SCREEN_HEIGHT / 2) + (ray->line_h / 2)) * step;
	y = ray->min_h;
	ray->wall_x = wall_x - floor(wall_x);
	while (y < ray->max_h)
	{
		pos_y = (int)tex_pos;
		tex_pos += step;
		if (texture->endian == 0)
		{
			color = pos_y * texture->line_size + pos_x
				* (texture->bits_per_pixel / 8);
		}
		put_pixel(data, ray->index, y, apply_shader(data, get_vect(ray->index,
					y, 0), *(int *)(texture->pixels + color), ray->proj));
		y++;
	}
}

int	dark_color(int color, double dist)
{
	int	dark;
	int	alpha;
	int	red;
	int	blue;
	int	green;

	dark = 100 - (100 * dist) / 10;
	if (dark < 0)
		dark = 0;
	alpha = ((color >> 24) & 0xff);
	red = ((double)((color >> 16) & 0xff) / 100) * dark * 0.1;
	green = ((double)((color >> 8) & 0xff) / 100) * dark * 0.1;
	blue = ((double)((color)&0xff) / 100) * dark * 0.1;
	return ((alpha << 24) + (red << 16) + (green << 8) + (blue));
}

int	apply_shader(t_data *data, t_vect pos, int color, double dist)
{
	color = dark_color(color, dist);
	color = flashlight_shader(data, pos, color, dist);
	return (color);
}
