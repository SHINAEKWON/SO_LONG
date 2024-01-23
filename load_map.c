/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:55:29 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/22 18:39:19 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_map_two(t_set *game)
{
	char	**map_copy;

	map_copy = make_floodfill_map(*game);
	if (map_copy == NULL)
	{
		ft_printf("Error\nFailed to copy the map for check.\n\n");
		return (0);
	}
	search_p(&game->p, map_copy);
	floodfill(map_copy, game->p.x, game->p.y);
	if (check_post_ff(map_copy) != 1)
	{
		ft_printf("Error\nInvalid path. Player cannot access all elements.\n\n");
		return (0);
	}
	return (1);
}

void	free_and_exit(char *map)
{
	free(map);
	exit (0);
}

int	load_map(char *map, t_set *game)
{
	if (check_map_elements(map) != 1)
	{
		ft_printf("Error\nMap must have valid map elements.\n\n");
		free_and_exit(map);
	}
	if (check_num_map_elem(map) != 1)
	{
		ft_printf("Error\nWrong map element numbers.\n\n");
		free_and_exit(map);
	}
	check_nb_collectible(map, game);
	if (check_map_width(map, game) != 1)
	{
		ft_printf("Error\nMap is not rectangle.\n\n");
		return (0);
	}
	if (check_wall(game) != 1)
	{
		ft_printf("Error\nInvalid map wall configuration.\n\n");
		return (0);
	}
	if (load_map_two(game) == 1)
		return (1);
	return (0);
}
