/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:39:19 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 19:55:08 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(t_set game, int error)
{
	static t_list	*stash = NULL;
	char			*line;
	int				lu;

	if (error == 1 || game.fd < 0 || BUFFER_SIZE <= 0
		|| read(game.fd, &line, 0) < 0)
		return (NULL);
	lu = 1;
	line = NULL;
	read_and_stash(game, &stash, &lu);
	if (stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	if (extract_line(stash, &line) == 1)
	{
		clean_stash(&stash);
		free(line);
		return (NULL);
	}
	clean_stash(&stash);
	if (line[0] == '\0')
		return (free_stash_line(stash, line), NULL);
	return (line);
}
// in case of error, try error == 1, free(stash)

void	read_and_stash(t_set game, t_list **stash, int *lu_ptr)
{
	char	*buf;

	while (!found_newline(*stash) && *lu_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		*lu_ptr = (int)read(game.fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *lu_ptr == 0) || *lu_ptr == -1)
		{
			free(buf);
			return ;
		}
		buf[*lu_ptr] = '\0';
		add_to_stash(stash, buf, *lu_ptr);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, int lu)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (lu + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < lu)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

int	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return (1);
	generate_line(line, stash);
	if (*line == NULL)
		return (1);
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j] = stash->content[i];
				j++;
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	return ((*line)[j] = '\0', 0);
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*c_n;
	int		i;
	int		j;

	c_n = malloc(sizeof(t_list));
	if (stash == NULL || c_n == NULL)
		return ;
	c_n->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	c_n->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (c_n->content == NULL)
		return ;
	j = 0;
	while (last->content [i])
		c_n->content[j++] = last->content[i++];
	c_n->content[j] = '\0';
	free_stash(*stash);
	*stash = c_n;
}
