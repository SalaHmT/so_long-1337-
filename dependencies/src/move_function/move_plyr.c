/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plyr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 05:05:52 by shamsate          #+#    #+#             */
/*   Updated: 2023/07/01 14:58:09 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	pressed_key(int key, t_mlx_c *st_game)
{
	t_mlx_c	*game;

	game = (t_mlx_c *)st_game;
	if (key == ESC_KEY)
		free_and_destro(game, "EXIT THE GAME!.");
	else if (key == UP_KEY)
		mv_up(game);
	else if (key == DOWN_KEY)
		mv_down(game);
	else if (key == LEFT_KEY)
		mv_left(game);
	else if (key == RIGHT_KEY)
		mv_right(game);
	mlx_clear_window(game->mlx, game->win_ptr);
	image_rendering(*game);
	return (0);
}
