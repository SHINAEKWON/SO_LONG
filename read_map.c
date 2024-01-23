/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:43:14 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/22 18:51:46 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(t_set *game)
{
	char	*line;
	char	*imported_map;

	line = "";
	imported_map = ft_strdup("");
	line = get_next_line(*game, 0);
	game->y_max = 0;
	while (line != NULL)
	{
		imported_map = ft_strjoin(imported_map, line);
		line = get_next_line(*game, 0);
		if (!line)
		{
			line = get_next_line(*game, 1);
		}
		game->y_max++;
	}
	return (imported_map);
}

int	check_map_elements(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'E'
			|| map[i] == 'P' || map[i] == 'C' || map[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_num_map_elem(char *map)
{
	int		i;
	short	e;
	short	p;
	short	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'E')
			e++;
		if (map[i] == 'P')
			p++;
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (e == 1 && p == 1 && c >= 1)
		return (1);
	return (0);
}

int	check_map_width(char *map, t_set *game)
{
	int	temp_width;
	int	i;

	i = 0;
	if (check_map_elements(map) && check_num_map_elem(map))
	{
		game->map = ft_split(map, '\n');
		game->x_max = ft_strlen(game->map[0]);
		temp_width = game->x_max;
		while (game->map[i])
		{
			temp_width = ft_strlen(game->map[i]);
			if (temp_width != game->x_max)
			{
				return (0);
			}
			i++;
		}
		i = game->y_max;
	}
	return (1);
}

int	check_wall(t_set *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (game->map[0][i])
		if (game->map[0][i++] != '1')
			return (0);
	i = 0;
	while (game->map[game->y_max - 1][i])
		if (game->map[game->y_max - 1][i++] != '1')
			return (0);
	while (game->map[j])
		if (!(game->map[j][0] == '1' && game->map[j++][game->x_max - 1] == '1'))
			return (0);
	return (1);
}
