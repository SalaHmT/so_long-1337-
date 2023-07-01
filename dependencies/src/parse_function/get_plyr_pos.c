/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plyr_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:24:28 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/24 17:41:36 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	get_plyr_pos(t_mlx_c *game)
{
	int	rw;
	int	cl;

	rw = -1;
	while (game->map.map[++rw])
	{
		cl = -1;
		while (game->map.map[rw][++cl])
		{
			if (game->map.map[rw][cl] == 'P')
			{
				game->map.plyr.i = rw;
				game->map.plyr.y = cl;
				return ;
			}
		}
	}
}
