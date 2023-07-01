/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:07:39 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/30 21:05:30 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include "mlx.h"
# include "../dependencies/src/ft_printf/include/ft_printf.h"

// *** Map ***
# define WALL '1'
# define COLL 'C'
# define PLYR 'P'
# define EXT 'E'
# define GRASS '0'
# define SQRE	64
# define BUFF_SIZE 256

// *** KEYS ***
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53
# define WIN_CLOSE 17

// *** STRUCT TYPE ***
typedef struct s_vec
{
	int		i;
	int		y;
}				t_vec;

typedef struct s_map
{
	char	**map;
	int		col;
	int		row;
	t_vec	plyr;
	t_vec	ext;
	int		coll;
}				t_map;

typedef struct s_mlx_conf
{
	void	*mlx;
	void	*win_ptr;
	void	*img_ptr;
	t_map	map;
	t_map	map2;
	size_t	move_cnt;
	int		fd;
	int		img_size;
	int		if_possible;
}				t_mlx_c;

// *** mlibx... ***

void	display_the_name(void);
void	free_and_destro(t_mlx_c *game, char *str);
char	*load_image(char c, int if_possible);
void	check_and_render(t_mlx_c game, int x, int y);
void	image_rendering(t_mlx_c game);
void	new_win(t_mlx_c *game);

// *** Get_Next_Line ***
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(char *s);
char	*ft_strjoin_l(char *s1, char *s2);
char	*get_ln(char *backup);
char	*read_ln(int fd, char *backup);
char	*get_sv_and_fr(char *backup);
char	*get_next_line(int fd);

// *** Libft_Function ***
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(const char *str, char c);
int		ft_strchr_i(char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(char *a, char *b);
size_t	ft_strlen_c(const char *str);
char	*ft_strchr(char *s, int c);

// check_map : parsing
void	check_dir(char	*nm_file);
void	check_map(char *nm_file, t_mlx_c *game);
int		check_map_format(t_mlx_c game);
int		check_char(t_mlx_c game);
int		check_extent(const char *str, const char *extention);
int		check_wall(t_mlx_c *game);
void	check_map(char *nm_file, t_mlx_c *game);
int		check_map_format(t_mlx_c game);
int		check_char(t_mlx_c game);
int		check_var(t_mlx_c game);
int		check_plyr(t_mlx_c game);
int		check_ext_nb(t_mlx_c game);
int		check_ext(t_mlx_c *game);
void	get_plyr_pos(t_mlx_c *game);
void	get_map(char *nm_file, t_mlx_c *game);
void	get_all_colls(t_mlx_c *game);
void	get_ext_pos(t_mlx_c *game);
void	map_free(t_mlx_c *game);
void	extent_error(char *nm_file);
void	err_wall(t_mlx_c *game, char *nm_file);
void	err_char(t_mlx_c *game, char *nm_file);
void	err_var(t_mlx_c *game, char *nm_file);
void	err_plyr(t_mlx_c *game, char *nm_file);
void	err_char(t_mlx_c *game, char *nm_file);
void	map_format(t_mlx_c *game, char *nm_file);
void	err_ext(t_mlx_c *game, char *nm_file);
int		len_map(int fd);
void	get_map2( char *nm_file, t_mlx_c *game);
void	check_is_valid_path(t_mlx_c *game);
int		check_plyr_path(t_mlx_c *game);

// ****** MOVEMENT FUNCTION ***********
void	mv_left(t_mlx_c *game);
void	mv_right(t_mlx_c *game);
void	mv_up(t_mlx_c *game);
void	mv_down(t_mlx_c *game);
int		pressed_key(int key, t_mlx_c *st_game);
#endif