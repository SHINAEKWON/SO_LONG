/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:35:16 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 23:16:45 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <bsd/string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>

# define TILE 64

// SO_LONG PARAMETER //

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_set
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		x_max;
	int		y_max;
	int		nb_collectible;
	int		x;
	int		y;
	t_pos	p;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*shikwon;
	void	*exit;
	int		screen_x;
	int		screen_y;
	int		window_x;
	int		window_y;
	char	*game_name;
}	t_set;

// GET_NEXT_LINE FUNCTIONS //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(t_set game, int error);
int		found_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	read_and_stash(t_set game, t_list **stash, int *lu_ptr);
void	add_to_stash(t_list **stash, char *buf, int lu);
int		extract_line(t_list *stash, char **line);
void	generate_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
size_t	ft_strlen(const char *str);
void	free_stash(t_list *stash);
void	free_stash_line(t_list *stash, char *line);

// FT_PRINTF FUNCTIONS //

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_uputnbr(unsigned int n);
int		ft_count_digit(unsigned long long nb);
int		ft_putnbr_base(unsigned long long nb, char *base);
int		ft_puthex(int i, char x);
int		ft_putpointer(unsigned long long nb);
int		ft_putnbr(int n);
int		nb_digit(int n);
int		ft_printf(const char *str, ...);

// LIBFT FUCTIONS //
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strnstr_tf(const char *big, const char *little, size_t len);

// EXTENSION CHECK //
void	valid_mapfile_ext(int ac, char *av);
void	game_open_check(t_set *game);

// MAP READING RELATED FUNCTIONS //
int		load_map(char *map, t_set *game);
char	*read_map(t_set *game);
int		check_map_elements(char *map);
int		check_num_map_elem(char *map);
int		check_map_width(char *map, t_set *game);
int		check_wall(t_set *game);

// PATH CHECK RELATED FUNCTIONS //
char	**make_floodfill_map(t_set game);
void	search_p(t_pos *p, char **map_copy);
void	floodfill(char **map_copy, int x, int y);
int		check_post_ff(char **map_copy);

// RENDERING & WINDOW RELATED FUNCTIONS //
int		ft_load_textures(t_set *game);
void	ft_draw_img(t_set *game);
int		ft_close_window(t_set *game);
int		handle_keypress(int keysym, t_set *game);

// ETC
void	count_movement(void);
void	check_nb_collectible(char *map, t_set *game);
void	ft_free(char **map);
void	free_and_exit(char *map);
int		check_empty_line(char *imported_map);
int		environment_check(char **env);

#endif
