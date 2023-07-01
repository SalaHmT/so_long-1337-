/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:02:29 by shamsate          #+#    #+#             */
/*   Updated: 2023/07/01 14:55:23 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_char_coll(t_mlx_c game)
{
	int	rw;
	int	cl;

	rw = -1;
	while (game.map2.map[++rw] != NULL)
	{
		cl = -1;
		while (game.map2.map[rw][++cl] != '\n' && game.map2.map[rw][cl] != '\0')
		{
			if (game.map2.map[rw][cl] == 'C')
				return (1);
		}
	}
	return (0);
}

int	check_ext(t_mlx_c *game)
{
	t_vec	e_ext;

	e_ext = game->map2.ext;
	if (game->map2.map[e_ext.i][e_ext.y - 1] == 'P')
		return (0);
	if (game->map2.map[e_ext.i][e_ext.y + 1] == 'P')
		return (0);
	if (game->map2.map[e_ext.i - 1][e_ext.y] == 'P')
		return (0);
	if (game->map2.map[e_ext.i + 1][e_ext.y] == 'P')
		return (0);
	return (1);
}

int	check_plyr_path(t_mlx_c *game)
{
	t_vec	plyrrr;

	plyrrr = game->map.plyr;
	if (game->map2.map[plyrrr.i][plyrrr.y - 1] == 'P')
		return (0);
	if (game->map2.map[plyrrr.i][plyrrr.y + 1] == 'P')
		return (0);
	if (game->map2.map[plyrrr.i - 1][plyrrr.y] == 'P')
		return (0);
	if (game->map2.map[plyrrr.i + 1][plyrrr.y] == 'P')
		return (0);
	return (1);
}

void	put_p_in_map(char **mp, int x, int y)
{
	if (mp[y][x + 1] == 'C' || mp[y][x + 1] == '0')
	{
		mp[y][x + 1] = 'P';
		put_p_in_map(mp, x + 1, y);
	}
	if (mp[y][x - 1] == 'C' || mp[y][x - 1] == '0')
	{
		mp[y][x - 1] = 'P';
		put_p_in_map(mp, x - 1, y);
	}
	if (mp[y + 1][x] == 'C' || mp[y + 1][x] == '0')
	{
		mp[y + 1][x] = 'P';
		put_p_in_map(mp, x, y + 1);
	}
	if (mp[y - 1][x] == 'C' || mp[y - 1][x] == '0')
	{
		mp[y - 1][x] = 'P';
		put_p_in_map(mp, x, y - 1);
	}
}

void	check_is_valid_path(t_mlx_c *game)
{
	t_vec	plyrr;

	get_plyr_pos(game);
	plyrr = game->map2.plyr;
	put_p_in_map(game->map2.map, plyrr.i, plyrr.y);
	if (check_char_coll(*game) || check_ext(game)
		|| check_plyr_path(game))
	{
		ft_printf("invalid path for one of ");
		ft_printf("<Collectibles> or <Exit> or <Player> :( \n");
		exit(1);
	}
}
