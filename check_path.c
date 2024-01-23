/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:56:36 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/21 15:00:40 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_floodfill_map(t_set game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)ft_calloc((game.y_max + 1), sizeof (char *));
	if (copy == NULL)
		return (NULL);
	while (i < game.y_max)
	{
		copy[i] = (char *)ft_calloc((game.x_max + 1), sizeof (char));
		if (copy[i] == NULL)
			return (NULL);
		ft_memcpy(copy[i], game.map[i], game.x_max);
		copy[i][ft_strlen(copy[i])] = '\0';
		i++;
	}
	copy[game.y_max] = NULL;
	return (copy);
}

void	search_p(t_pos *p, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'P')
			{
				p->y = i;
				p->x = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	floodfill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'X' || map_copy[y][x] == 'E')
		return ;
	map_copy[y][x] = 'X';
	floodfill (map_copy, (x + 1), y);
	floodfill (map_copy, (x - 1), y);
	floodfill (map_copy, x, (y - 1));
	floodfill (map_copy, x, (y + 1));
}

int	check_post_ff(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '1' || map_copy[i][j] == 'X'
				|| map_copy[i][j] == 'E')
				j++;
			else
			{
				ft_free(map_copy);
				return (0);
			}
		}
		i++;
	}
	ft_free(map_copy);
	return (1);
}
