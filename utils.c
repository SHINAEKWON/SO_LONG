/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:53:20 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 19:32:26 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_nb_collectible(char *map, t_set *game)
{
	int	i;

	i = 0;
	game->nb_collectible = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			game->nb_collectible++;
		i++;
	}
}

int	check_empty_line(char *imported_map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (imported_map[0] != '1')
	{
		ft_printf("Error\nThis map has empty line(s).\n\n");
		return (0);
	}
	while (imported_map[i] && imported_map[j])
	{
		if (imported_map[i] == '\n' && imported_map[j] == '\n')
		{
			ft_printf("Error\nThis map has empty line(s).\n\n");
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}
