/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:27:05 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/23 00:23:56 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_ext_nb(t_mlx_c game)
{
	int	i;
	int	ext;

	i = 0;
	ext = 0;
	while (game.map.map[i])
	{
		if (ft_strchr_i(game.map.map[i], 'E') == 1)
			ext++;
		i++;
	}
	return (ext == 1);
}

void	err_ext(t_mlx_c *game, char *nm_file)
{
	ft_printf("So_Long :%s: One Exit allowed .. :(\n", nm_file);
	map_free(game);
}
