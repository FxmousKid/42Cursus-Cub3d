/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:58:13 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/11 05:55:00 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split);

static void	get_assets(char *assets[7])
{
	assets[0] = "NO";
	assets[1] = "SO";
	assets[2] = "WE";
	assets[3] = "EA";
	assets[4] = "F";
	assets[5] = "C";
	assets[6] = "D";
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

static bool	check_if_keys_valid(char *line)
{
	static int	lookup[7];
	static char	*assets[7];
	int			i;

	get_assets(assets);
	i = 0;
	while (i < 7)
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
			return (true);
		}
		i++;
	}
	ft_printf("%sError\n%s", RED_TXT, END_TXT);
	ft_printf("Unknown key spotted\n");
	return (false);
}

// Will check the formats valdity (appears once, etc...) and file valdity
bool	check_assets_format(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_isalpha(line[0]) && !check_if_keys_valid(line))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}
