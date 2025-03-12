/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:04:04 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/12 12:26:54 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

int		check_file_name(char *file);
int		parsing_map(t_data *data, char *file_map);
int		parse_file(t_data *data, int fd);
int		parse_texture(t_data *data, int fd);
int		fill_map(t_data *data, int fd);
int		parse_texture_wall(t_data *data, int fd);
int		fill_map_row(t_data *data, char *line, int x, int y);
void	print_file(int fd);

#endif