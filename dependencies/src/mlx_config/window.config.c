/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:47:33 by shamsate          #+#    #+#             */
/*   Updated: 2023/07/01 14:57:12 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	close_win(t_mlx_c *game)
{
	free_and_destro(game, "Window Closed .");
	return (0);
}

void	new_win(t_mlx_c *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->map.col * SQRE,
			game->map.row * SQRE, "SO_LONG");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, close_win, game);
}
