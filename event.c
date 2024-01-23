/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:58:41 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/29 00:14:41 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_set *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx_ptr, game->collectible);
	if (game->shikwon)
		mlx_destroy_image(game->mlx_ptr, game->shikwon);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free(game->map);
	ft_printf("\nNow closed %s. Thank you for playing!\n\n", game->game_name);
	exit(0);
}

void	count_movement(void)
{
	static int	i;

	ft_printf("Move(s) : %d\n", ++i);
}

static void	handle_c_and_zero(t_set *game, int x, int y)
{
	if (game->map[game->p.y + y][game->p.x + x] == 'C')
	{
		if (game->nb_collectible != 0)
			game->nb_collectible--;
		game->map[game->p.y + y][game->p.x + x] = 'P';
		game->map[game->p.y][game->p.x] = '0';
		game->p.y = game->p.y + y;
		game->p.x = game->p.x + x;
		ft_draw_img(game);
		return ;
	}
	if (game->map[game->p.y + y][game->p.x + x] == '0')
	{
		game->map[game->p.y + y][game->p.x + x] = 'P';
		game->map[game->p.y][game->p.x] = '0';
		game->p.y = game->p.y + y;
		game->p.x = game->p.x + x;
		ft_draw_img(game);
		return ;
	}
}

void	keypress_movement(t_set *game, int x, int y)
{
	int	size;

	if (!(game->map[game->p.y + y][game->p.x + x] == '1') &&
			!(game->map[game->p.y + y][game->p.x + x] == 'E'))
		count_movement();
	if (game->nb_collectible == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit);
		game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
				"img/exit_open.xpm", &size, &size);
		if (game->map[game->p.y + y][game->p.x + x] == 'E')
			ft_close_window(game);
	}
	if (game->map[game->p.y + y][game->p.x + x] == '1')
		return ;
	if (game->map[game->p.y + y][game->p.x + x] == 'C')
	{
		handle_c_and_zero(game, x, y);
		return ;
	}
	if (game->map[game->p.y + y][game->p.x + x] == '0')
	{
		handle_c_and_zero(game, x, y);
		return ;
	}
}

int	handle_keypress(int keysym, t_set *game)
{
	if (keysym == XK_Escape)
	{
		ft_close_window(game);
	}
	if (keysym == XK_a || keysym == XK_Left)
		keypress_movement(game, -1, 0);
	if (keysym == XK_s || keysym == XK_Down)
		keypress_movement(game, 0, 1);
	if (keysym == XK_d || keysym == XK_Right)
		keypress_movement(game, 1, 0);
	if (keysym == XK_w || keysym == XK_Up)
		keypress_movement(game, 0, -1);
	return (1);
}
