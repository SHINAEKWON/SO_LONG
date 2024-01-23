/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:27:55 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/15 19:23:58 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word_on;
	size_t	word_nb;

	i = 0;
	word_on = 0;
	word_nb = 0;
	while (s[i])
	{
		if (s[i] != c && word_on == 0)
		{
			word_on = 1;
			word_nb++;
		}
		else if (s[i] == c && word_on == 1)
			word_on = 0;
		else if (s[i] == c && word_on == 0)
			word_nb += 0;
		i++;
	}
	return (word_nb);
}

static size_t	count_letters(const char *s, char c, size_t i)
{
	size_t	length_word;

	length_word = 0;
	while (s[i] && s[i] != c)
	{
		length_word++;
		i++;
	}
	return (length_word);
}	

static void	*dofree(char **res, size_t w_ctr)
{
	while (w_ctr-- > 0)
		free(res[w_ctr]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	w_ctr;
	char	**res;
	size_t	nb_words;

	if (!s)
		return (NULL);
	i = 0;
	w_ctr = 0;
	nb_words = count_words(s, c);
	res = (char **)ft_calloc(sizeof(char *), nb_words + 1);
	if (!res)
		return (NULL);
	while (w_ctr < nb_words)
	{
		while (s[i] && s[i] == c)
			i++;
		res[w_ctr] = ft_substr(s, i, count_letters(s, c, i));
		if (!res[w_ctr])
			return (dofree(res, w_ctr));
		i = i + count_letters(s, c, i);
		w_ctr++;
	}
	return (res);
}
