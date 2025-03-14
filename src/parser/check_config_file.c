/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:26:47 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/14 17:56:07 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "macro.h"

bool	check_assets_format(int fd, int *pos_map);
bool	check_assets_file(int fd);
bool	check_map(int fd, int pos_map);

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

bool	check_assets_file(int fd)
{
	char	*line;
	char	**tab;

	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		if (!tab[1])
			return (free_split(tab), free(line), true);
		tab[1][ft_strlen(tab[1]) - 1] = '\0';
		if (access(tab[1], F_OK | R_OK) < 0)
		{
			ft_printf("%sError\n%s", RED_TXT, END_TXT);
			ft_printf("Unable to open file: [%s]\n", tab[1]);
			return (perror(""), free_split(tab), false);
		}
		free_split(tab);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

void	print_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n");
}

bool	check_config_file(char *config_file_path)
{
	int	fds[3];
	int	pos_map;

	if (ft_strncmp(config_file_path + ft_strlen(config_file_path) - 4, ".cub",
			ft_strlen(config_file_path + ft_strlen(config_file_path) - 4)) != 0)
		return (ft_printf("%sFile name wrong%s\n", RED_TXT, END_TXT), false);
	fds[0] = open(config_file_path, O_RDONLY | __O_DSYNC);
	fds[1] = open(config_file_path, O_RDONLY | __O_DSYNC);
	fds[2] = open(config_file_path, O_RDONLY | __O_DSYNC);
	if (fds[0] < 0 || fds[1] < 0 || fds[2] < 0)
	{
		ft_printf("%sUnable to open file: %s", RED_TXT, END_TXT);
		perror("");
		return (false);
	}
	if (!check_assets_format(fds[0], &pos_map))
		return (close(fds[0]), close(fds[1]), close(fds[2]), false);
	close(fds[0]);
	if (!check_assets_file(fds[1]))
		return (close(fds[1]), close(fds[2]), false);
	close(fds[1]);
	if (!check_map(fds[2], pos_map))
		return (close(fds[2]), false);
	close(fds[2]);
	return (true);
}
