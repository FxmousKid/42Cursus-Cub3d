/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:04:04 by ptheo             #+#    #+#             */
/*   Updated: 2025/01/30 18:26:48 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

int	check_file_name(char *file);
int	parsing_map(t_data *data, char *file_map);
int	parse_file(t_data *data, int fd);
int	get_texture(t_data *data, int fd);
int	fill_map(t_data *data, int fd);

#endif