/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:55:26 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/30 21:05:44 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	get_map2( char *nm_file, t_mlx_c *game)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(nm_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("So_Long:%s: This File Or Dir Not Exist.. :(\n", nm_file);
		exit (EXIT_FAILURE);
	}
	game->map2.row = len_map(fd);
	close(fd);
	game->map2.map = malloc(sizeof(char *) * (game->map2.row + 1));
	if (!game->map2.map)
	{
		ft_printf("Malloc failed to allocate enough memory. :(\n");
		exit(EXIT_FAILURE);
	}
	game->map2.map[game->map2.row] = 0;
	fd = open (nm_file, O_RDONLY);
	while (++i < game->map2.row)
		game->map2.map[i] = get_next_line(fd);
	close(fd);
}
