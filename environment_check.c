/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:09:11 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 23:59:58 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	environment_check(char **env)
{
	int	a;
	int	nb_env;	
	int	text_found;

	a = 0;
	if (env[0] == NULL || !*env)
		return (printf("\nEnvironment error has occured.\n\n"), 0);
	nb_env = 0;
	while (env[nb_env])
		nb_env++;
	text_found = 0;
	while (a < nb_env)
	{
		if (ft_strnstr_tf(env[a], "DISPLAY", ft_strlen(env[a])) == 1)
			a++;
		else
		{
			text_found++;
			a++;
		}
	}
	if (text_found == 0)
		return (printf("\nEnvironment error has occured.\n\n"), 0);
	return (1);
}
