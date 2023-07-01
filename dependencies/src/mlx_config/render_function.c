/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:41:00 by shamsate          #+#    #+#             */
/*   Updated: 2023/07/01 14:56:33 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

char	*load_image(char c, int if_possible)
{
	char	*rslt;

	(void)if_possible;
	rslt = NULL;
	if (c == WALL)
		rslt = "dependencies/assets/textures/wall.xpm";
	else if (c == COLL)
		rslt = "dependencies/assets/textures/coll.xpm";
	else if (c == PLYR)
		rslt = "dependencies/assets/textures/plyr.xpm";
	else if (c == EXT)
	{
		if (if_possible)
			rslt = "dependencies/assets/textures/exit_open.xpm";
		else
			rslt = "dependencies/assets/textures/exit_closed.xpm";
	}
	else
		rslt = "dependencies/assets/textures/Grass.xpm";
	return (rslt);
}

void	check_and_render(t_mlx_c game, int x, int y)
{
	char	*img_location;

	if (game.map.coll == 0)
		game.if_possible = 1;
	img_location = load_image(game.map.map[x][y], game.if_possible);
	if (img_location)
	{
		game.img_ptr = mlx_xpm_file_to_image(game.mlx, img_location,
				&game.img_size, &game.img_size);
		mlx_put_image_to_window(game.mlx, game.win_ptr,
			game.img_ptr, y * SQRE, x * SQRE);
		mlx_destroy_image(game.mlx, game.img_ptr);
	}
}

void	image_rendering(t_mlx_c game)
{
	int	x;
	int	y;

	x = -1;
	game.img_size = SQRE;
	while (game.map.map[++x])
	{
		y = 0;
		while (game.map.map[x][y] && game.map.map[x][y] != '\n')
		{
			check_and_render(game, x, y);
			y++;
		}
	}
}
