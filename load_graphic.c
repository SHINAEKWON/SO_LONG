/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:00:39 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/20 18:26:47 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_textures(t_set *game)
{
	int	size;

	game->shikwon = mlx_xpm_file_to_image(game->mlx_ptr,
			"img/shikwon.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"img/exit.xpm", &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"img/floor.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"img/wall.xpm", &size, &size);
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"img/collectible.xpm", &size, &size);
	if (game->shikwon == NULL || game->exit == NULL || game->floor == NULL
		|| game->wall == NULL || game->collectible == NULL)
		return (0);
	return (1);
}

void	ft_draw_img(t_set *game)
{
	game->y = 0;
	while (game->y < game->y_max)
	{
		game->x = 0;
		while (game->x < game->x_max)
		{
			if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->shikwon, (TILE * game->x), (TILE * game->y));
			else if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall, (TILE * game->x), (TILE * game->y));
			else if (game->map[game->y][game->x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->floor, (TILE * game->x), (TILE * game->y));
			else if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->collectible, (TILE * game->x), (TILE * game->y));
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->exit, (TILE * game->x), (TILE * game->y));
			game->x++;
		}
	game->y++;
	}
}
