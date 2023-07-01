/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:31:40 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/19 15:48:40 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	mv_right(t_mlx_c *game)
{
	if (game->map.map[game->map.plyr.i][game->map.plyr.y + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.plyr.i][game->map.plyr.y + 1],
			&game->map.map[game->map.plyr.i][game->map.plyr.y]);
		game->map.plyr.y++;
		ft_printf("[MOVED RIGHT] => %u\n", ++game->move_cnt);
	}
	else if (game->map.map[game->map.plyr.i][game->map.plyr.y + 1] == 'C')
	{
		game->map.coll--;
		game->map.map[game->map.plyr.i][game->map.plyr.y] = '0';
		game->map.map[game->map.plyr.i][game->map.plyr.y + 1] = 'P';
		game->map.plyr.y++;
	}
	else if (game->map.map[game->map.plyr.i][game->map.plyr.y + 1] == 'E'
		&& !game->map.coll)
		free_and_destro(game, "NICE .. GOOD GAME! :) ");
}
