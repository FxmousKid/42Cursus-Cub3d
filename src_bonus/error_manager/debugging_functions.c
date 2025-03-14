/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:06:11 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/14 23:53:49 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Function used to debug errors flow, will only trigger when building
 * project with 'make debug'*/
#ifdef DEBUG

void	debug(char *str)
{
	printf("%s==%d== %s%s", RED_TXT, getpid(), str, END_TXT);
}

#else

void	debug(char *str)
{
	(void)str;
}
#endif

void	ft_err(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
}
