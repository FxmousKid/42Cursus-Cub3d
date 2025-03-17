/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:30:43 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/17 18:13:30 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_isnumbers(char *line);

bool	check_color_format_utils(char **split1)
{
	int		i;
	char	**split2;

	split2 = ft_split(split1[1], ", ");
	free_tab((void **)split1, 3);
	if (split2 == NULL)
		return (false);
	i = 0;
	while (split2[i])
	{
		if (ft_isnumbers(split2[i]) == false || ft_atoi(split2[i]) > 255)
		{
			ft_printf("%sWrong number argument\n%s", RED_TXT, END_TXT);
			return (free_tab((void **)split2, 3), false);
		}
		i++;
	}
	i = 0;
	while (split2[i])
		free(split2[i++]);
	free(split2);
	if (i != 3)
		return (ft_printf("Wrong color argument: need 3 numbers\n"), false);
	return (true);
}

bool	check_color_format(char *line)
{
	int		i;
	int		count;
	char	**split1;

	split1 = ft_split(line, " \t");
	if (split1 == NULL)
		return (false);
	if (split1[1] == NULL)
		return (free(split1[0]), free(split1), false);
	i = 0;
	count = 0;
	while (split1[1][i])
	{
		if (split1[1][i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (ft_printf("Wrong color argument: need R,G,B \n"),
			free_tab((void **)split1, len_tab((void **)split1)), false);
	split1[1][ft_strlen(split1[1]) - 1] = '\0';
	return (check_color_format_utils(split1));
}

bool	valid_neighbour_floor(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == '1' || c == '2'
		|| c == '0');
}

bool	check_single_floor_pos(int i, int j, t_map map)
{
	if ((i == 0) || (i > 0 && !valid_neighbour_floor(map[i - 1][j])))
		return (false);
	if ((j == 0) || (j > 0 && !valid_neighbour_floor(map[i][j - 1])))
		return (false);
	if ((j == 1023) || (j < 1024 && !valid_neighbour_floor(map[i][j + 1])))
		return (false);
	if ((i == 1023) || (i < 1024 && !valid_neighbour_floor(map[i + 1][j])))
		return (false);
	return (true);
}

void	replace_tab_by_space(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			j = ft_strlen(line);
			while (j > i)
			{
				line[j + 3] = line[j];
				j--;
			}
			j = 0;
			while (j < 4)
			{
				line[i++] = ' ';
				j++;
			}
			i -= 1;
		}
		i++;
	}
}
