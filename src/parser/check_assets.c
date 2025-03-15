/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:58:13 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/15 21:48:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_split(char **split);

static void	get_assets(char *assets[7])
{
	assets[0] = "NO";
	assets[1] = "SO";
	assets[2] = "WE";
	assets[3] = "EA";
	assets[4] = "F";
	assets[5] = "C";
}

static bool	is_asset_name_valid(char *line, char *real_asset)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (free_split(split), false);
	if (ft_strncmp(real_asset, split[0], ft_strlen(split[0])))
		return (free_split(split), false);
	free_split(split);
	return (true);
}

bool		check_color_format(char *line);

static bool	check_if_keys_valid(char *line, int lookup[], int line_pos,
		int *pos_map)
{
	static char	*assets[7];
	int			i;

	get_assets(assets);
	i = -1;
	while (++i < 6)
	{
		if (is_asset_name_valid(line, assets[i]))
		{
			if (lookup[i] == 1)
			{
				ft_printf("%sError\n%s", RED_TXT, END_TXT);
				ft_printf("The key %s appears more than once\n", assets[i]);
				return (false);
			}
			lookup[i] = 1;
			*pos_map = line_pos;
			if (ft_strncmp(assets[i], "F", 1) == 0 || ft_strncmp(assets[i], "C",
					1) == 0)
				return (check_color_format(line));
			return (true);
		}
	}
	ft_printf("%sError\n%sUnknown key spotted\n", RED_TXT, END_TXT);
	return (false);
}

// Will check the formats valdity (appears once, etc...) and file valdity
bool	check_assets_format(int fd, int *pos_map)
{
	static int	lookup[7];
	char		*line;
	int			i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_isalpha(line[0]) && !check_if_keys_valid(line, lookup, i,
				pos_map))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (lookup[i++] == 0)
		{
			ft_printf("%sError: %sKey is missing\n", RED_TXT, END_TXT);
			return (false);
		}
	}
	return (true);
}
