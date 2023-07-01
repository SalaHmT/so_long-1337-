/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:32:34 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/19 15:48:45 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	mv_down(t_mlx_c *game)
{
	if (game->map.map[game->map.plyr.i + 1][game->map.plyr.y] == '0')
	{
		ft_swap(&game->map.map[game->map.plyr.i + 1][game->map.plyr.y],
			&game->map.map[game->map.plyr.i][game->map.plyr.y]);
		game->map.plyr.i++;
		ft_printf("[MOVED DOWN] => %u\n", ++game->move_cnt);
	}
	else if (game->map.map[game->map.plyr.i + 1][game->map.plyr.y] == 'C')
	{
		game->map.coll--;
		game->map.map[game->map.plyr.i][game->map.plyr.y] = '0';
		game->map.map[game->map.plyr.i + 1][game->map.plyr.y] = 'P';
		game->map.plyr.i++;
	}
	else if (game->map.map[game->map.plyr.i + 1][game->map.plyr.y] == 'E'
		&& !game->map.coll)
		free_and_destro(game, "NICE .. GOOD GAME! :) ");
}
