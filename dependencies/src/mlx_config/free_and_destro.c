/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 02:02:11 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/19 16:49:35 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	free_and_destro(t_mlx_c *game, char *str)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->win_ptr);
	if (ft_strcmp(str, "NICE .. GOOD GAME! :) ") == 0)
		ft_printf("\n\n{ NICE .. GOOD GAME! :) }");
	else
		ft_printf("\n%s\n", str);
	exit(EXIT_SUCCESS);
}
