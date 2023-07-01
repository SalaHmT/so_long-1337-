/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:38:13 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/19 17:15:33 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	mv_left(t_mlx_c *game)
{
	if (game->map.map[game->map.plyr.i][game->map.plyr.y - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.plyr.i][game->map.plyr.y - 1],
			&game->map.map[game->map.plyr.i][game->map.plyr.y]);
			game->map.plyr.y--;
		ft_printf("[MOVED LEFT] => %u\n", ++game->move_cnt);
	}
	else if (game->map.map[game->map.plyr.i][game->map.plyr.y - 1] == 'C')
	{
		game->map.coll--;
		game->map.map[game->map.plyr.i][game->map.plyr.y] = '0';
		game->map.map[game->map.plyr.i][game->map.plyr.y - 1] = 'P';
		game->map.plyr.y--;
	}
	else if (game->map.map[game->map.plyr.i][game->map.plyr.y - 1] == 'E'
		&& !game->map.coll)
		free_and_destro(game, "NICE .. GOOD GAME! :) " );
}
