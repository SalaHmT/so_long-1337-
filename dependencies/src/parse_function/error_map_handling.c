/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:17:32 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/18 18:15:16 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	err_var(t_mlx_c *game, char *nm_file)
{
	ft_printf("%s  so_long: : Player or Exit or Collectible not Exist!!.\n",
		nm_file);
	map_free(game);
}

void	map_format(t_mlx_c *game, char *nm_file)
{
	ft_printf("%s -  So_Long :: The Map Format not rectangular. :(\n", nm_file);
	map_free(game);
}

void	extent_error(char *nm_file)
{
	ft_printf ("%s  - So_Long - : Incorrect Extention. :(\n",
		nm_file);
	exit(EXIT_FAILURE);
}

void	err_wall(t_mlx_c *game, char *nm_file)
{
	ft_printf("%s so_long:  walls incompatible or invalid :(!.\n",
		nm_file);
	map_free(game);
}

void	err_char(t_mlx_c *game, char *nm_file)
{
	ft_printf("%s so_long:   invalid caracter in map.. :(!.\n", nm_file);
	map_free(game);
}
