/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:46:59 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/03 03:44:51 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect	get_vect(double x, double y, double z)
{
	t_vect	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_square	get_square(t_vect v1, t_vect v2, t_vect v3, t_vect v4)
{
	t_square	s;

	s.top_left = v1;
	s.top_right = v2;
	s.bot_left = v3;
	s.bot_right = v4;
	return (s);
}
