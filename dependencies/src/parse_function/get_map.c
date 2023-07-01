/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:30:27 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/24 17:39:54 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	get_map( char *nm_file, t_mlx_c *game)
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
	game->map.row = len_map(fd);
	close(fd);
	game->map.map = malloc(sizeof(char *) * (game->map.row + 1));
	if (!game->map.map)
	{
		ft_printf("Malloc failed to allocate enough memory. :(\n");
		exit(EXIT_FAILURE);
	}
	game->map.map[game->map.row] = 0;
	fd = open (nm_file, O_RDONLY);
	while (++i < game->map.row)
		game->map.map[i] = get_next_line(fd);
	close(fd);
}
