/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:04:04 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/15 18:33:30 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

typedef char	t_map[1024][1024];

int				check_file_name(char *file);
int				parsing_map(t_data *data, char *file_map);
int				parse_file(t_data *data, int fd);
int				parse_texture(t_data *data, int fd);
int				fill_map(t_data *data, int fd);
int				parse_texture_utils(t_data *data, char **name);
int				fill_map_row(t_data *data, char *line, int x, int y);
void			print_file(int fd);

bool			valid_neighbour_floor(char c);
bool			check_single_floor_pos(int i, int j, t_map map);
void			replace_tab_by_space(char *line);

#endif