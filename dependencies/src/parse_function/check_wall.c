/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:55:10 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/24 17:36:36 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_wall(t_mlx_c *game)
{
	int	i;
	int	j;

	i = -1;
	game->map.col = ft_strlen_c(game->map.map[0]) - 1;
	while (++i < game->map.row)
	{
		j = -1;
		while (game->map.map[i][++j] != '\n' && j < game->map.col
			&& game->map.map[i][j])
		{
			if (i == 0 || i == game->map.row - 1)
				if (game->map.map[i][j] != '1')
					return (1);
			if (j == 0 || j == game->map.col - 1)
				if (game->map.map[i][j] != '1')
					return (1);
		}
	}
	return (0);
}
