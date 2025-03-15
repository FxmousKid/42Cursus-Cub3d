/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:23:28 by theo              #+#    #+#             */
/*   Updated: 2025/03/15 18:47:33 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture(t_data *data, t_img *img, char *p)
{
	char	*path;

	path = ft_strtrim(p, "\n");
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width,
			&img->height);
	if (img->img == NULL)
		return (ft_printf("%sEnable to open file:%s %s", RED_TXT, END_TXT, p),
			free(path), free(p), -1);
	img->pixels = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	free(path);
	free(p);
	if (img->pixels == NULL)
		return (-1);
	return (1);
}

t_img	*get_side_texture(t_data *data, t_ray *ray)
{
	if (ray->is_door)
	{
		return (&data->texture_door);
	}
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

void	get_wall_x(t_data *data, t_ray *ray)
{
	if (ray->w_side == 0)
		ray->wall_x = data->player.index.y + ray->proj * ray->ray.y;
	else
		ray->wall_x = data->player.index.x - ray->proj * ray->ray.x;
}

void	draw_texture(t_data *data, t_img *texture, t_ray *ray)
{
	unsigned int	color;
	int				y;
	double			step;
	double			tex_pos;
	t_vect			pos;

	get_wall_x(data, ray);
	pos.x = (int)((ray->wall_x - floor(ray->wall_x)) * texture->width);
	step = 1.0 * ((double)texture->height / (double)ray->line_h);
	tex_pos = (ray->min_h - (SCREEN_HEIGHT / 2) + (ray->line_h / 2)) * step;
	y = ray->min_h;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	while (y < ray->max_h)
	{
		pos.y = (int)tex_pos;
		tex_pos += step;
		if (texture->endian == 0)
		{
			color = pos.y * texture->line_size + pos.x
				* (texture->bits_per_pixel / 8);
		}
		data->frame[y][ray->index] = apply_shader(data, get_vect(ray->index, y,
					0), *(int *)(texture->pixels + color), ray->proj);
		y++;
	}
}
