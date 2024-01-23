/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:34:42 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/29 00:00:24 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_window_size(t_set *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	ft_printf("\nScreen size : %d x %d\n", game->screen_x, game->screen_y);
	game->window_x = game->x_max * TILE;
	game->window_y = game->y_max * TILE;
	ft_printf("Window size : %d x %d\n", game->window_x, game->window_y);
	if (game->window_x < game->screen_x && game->window_y < game->screen_y)
		ft_printf("... OK\n\n");
	else
	{
		ft_printf("\nMap is too big for the screen.\n\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return (0);
	}
	return (1);
}

static int	ft_create_window(t_set *game)
{
	game->mlx_ptr = mlx_init();
	if (check_window_size(game) == 0)
		return (0);
	if (game->mlx_ptr == NULL)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->window_x), (game->window_y),
			game->game_name);
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (0);
	}
	if (ft_load_textures(game) == 0)
	{
		ft_printf("Error\nCannot find all the image files.\n\n");
		ft_close_window(game);
		return (0);
	}	
	ft_draw_img(game);
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_close_window, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_set	game;
	char	*map;

	if (environment_check(env) == 0)
		return (1);
	valid_mapfile_ext(ac, av[1]);
	game.game_name = "Shikwon Gets Everything ! <3";
	game.fd = open(av[1], O_RDONLY);
	game_open_check(&game);
	map = read_map(&game);
	if (check_empty_line(map) == 0)
		return (free(map), 1);
	ft_printf("Map imported...\n\n%s\n\n", map);
	if (load_map(map, &game) == 0)
	{
		free(map);
		ft_free(game.map);
		return (1);
	}
	free(map);
	if (ft_create_window(&game) == 0)
		return (ft_free(game.map), 1);
	return (0);
}
