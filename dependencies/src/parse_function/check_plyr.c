/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plyr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 01:21:02 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/30 21:08:44 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_plyr(t_mlx_c game)
{
	int	i;
	int	plyr;

	i = -1;
	plyr = 0;
	while (game.map.map[++i])
	{
		if (ft_strchr_i(game.map.map[i], 'P') == 1)
			plyr++;
	}
	return (plyr == 1);
}

void	err_plyr(t_mlx_c *game, char *nm_file)
{
	ft_printf("So_Long :%s: One player allowed .. :(\n", nm_file);
	map_free(game);
}
