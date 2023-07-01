/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:25:13 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/19 17:13:22 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	mv_up(t_mlx_c *game)
{
	if (game->map.map[game->map.plyr.i - 1][game->map.plyr.y] == '0')
	{
		ft_swap(&game->map.map[game->map.plyr.i - 1][game->map.plyr.y],
			&game->map.map[game->map.plyr.i][game->map.plyr.y]);
		game->map.plyr.i--;
		ft_printf("[MOVED UP] => %u\n", ++ game->move_cnt);
	}
	else if (game->map.map[game->map.plyr.i - 1][game->map.plyr.y] == 'C')
	{
		game->map.coll--;
		game->map.map[game->map.plyr.i][game->map.plyr.y] = '0';
		game->map.map[game->map.plyr.i - 1][game->map.plyr.y] = 'P';
		game->map.plyr.i--;
	}
	else if (game->map.map[game->map.plyr.i - 1][game->map.plyr.y] == 'E'
		&& !game->map.coll)
		free_and_destro(game, "NICE .. GOOD GAME! :) ");
}
