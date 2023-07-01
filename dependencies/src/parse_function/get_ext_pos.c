/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ext_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:03:19 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/30 21:06:06 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	get_ext_pos(t_mlx_c *game)
{
	int	rw;
	int	cl;

	rw = 0;
	while (game->map2.map[rw])
	{
		cl = 0;
		while (game->map2.map[rw][cl])
		{
			if (game->map2.map[rw][cl] == 'E')
			{
				game->map2.ext.i = rw;
				game->map2.ext.y = cl;
				return ;
			}
			cl++;
		}
		rw++;
	}
}
