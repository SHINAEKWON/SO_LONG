/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:34:53 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 19:49:56 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename) - 1;
	if (filename[i] == 'r' && filename[i - 1] == 'e'
		&& filename[i - 2] == 'b' && filename[i - 3] == '.')
		return (1);
	return (0);
}

void	valid_mapfile_ext(int ac, char *av)
{
	if (ac != 2)
	{
		ft_printf("\nError\n");
		ft_printf("To launch the game, please select a map file.\n");
		ft_printf("./so_long [map file name : *.ber]\n\n");
		exit (1);
	}
	if (check_extension(av) == 0)
	{
		ft_printf("\nError\n");
		ft_printf("Map file must have [.ber] extension.\n\n");
		exit (1);
	}
}

void	game_open_check(t_set *game)
{
	if (game->fd < 0)
	{
		ft_printf("\nError has occured while opening the file.\n");
		ft_printf("Suggestion : CHECK FILE PERMISSION\n\n");
		ft_printf("Please try again.\n\n");
		exit (1);
	}
}
