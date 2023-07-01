/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:02:01 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/30 18:35:14 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_c	game;

	if (argc != 2)
	{
		ft_printf(" Arg not valid     :( \n");
		exit(EXIT_FAILURE);
	}
	display_the_name();
	check_map(argv[1], &game);
	game.mlx = mlx_init();
	new_win(&game);
	image_rendering(game);
	mlx_hook(game.win_ptr, 2, 0, *pressed_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
