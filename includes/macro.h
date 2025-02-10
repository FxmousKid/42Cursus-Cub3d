/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:21:08 by ptheo             #+#    #+#             */
/*   Updated: 2025/02/10 21:05:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define RED_TXT "\e[0;31m"
# define GREEN_TXT "\e[0;32m"
# define YELLOW_TXT "\e[0;33m"
# define BLUE_TXT "\e[0;34m"
# define PURPLE_TXT "\e[0;35m"
# define CYAN_TXT "\e[0;36m"
# define GREY_TXT "\e[0;37m"
# define WHITE_TXT "\e[0;39m"
# define BOLD_TXT "\e[1m"
# define UNDERLINE_TXT "\e[4m"
# define REVERSE_TXT "\e[7m"
# define HIDDEN_TXT "\e[8m"
# define END_TXT "\e[0m"

# define WHITE_ARGB 0x00FFFFFF
# define YELLOW_ARGB 0x00FFFF00
# define RED_ARGB 0x00FF0000
# define GREEN_ARGB 0x0000FF00
# define BLUE_ARGB 0x000000FF
# define COLOR_MAX 0xFFFFFFFF
# define GREY_ARGB 0x80808080
# define BLACK_ARGB 0x00000000

# define SCREEN_HEIGHT 720
# define SCREEN_WIDTH 1080

# define PI 3.14159265359

# define MAP_SIZE_MAX 200

#endif