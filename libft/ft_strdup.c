/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:25:33 by shikwon           #+#    #+#             */
/*   Updated: 2023/07/24 15:24:54 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_src;
	char	*s_tmp;
	int		src_len;
	int		i;

	i = 0;
	s_tmp = (char *)s;
	src_len = ft_strlen(s_tmp);
	new_src = NULL;
	new_src = (char *)malloc(sizeof(char) * (src_len + 1));
	if (new_src == NULL)
		return (0);
	while (s_tmp[i])
	{
		new_src[i] = s_tmp[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}
