/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:05:17 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/30 21:09:49 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	check_map(char *nm_file, t_mlx_c *game)
{
	check_dir(nm_file);
	if (check_extent(nm_file, ".ber") != 0)
		extent_error(nm_file);
	get_map(nm_file, game);
	get_map2(nm_file, game);
	if (check_char(*game) == 0)
		err_char(game, nm_file);
	if (check_char(*game) == 2)
		err_plyr(game, nm_file);
	if (check_map_format(*game) == 1)
		map_format(game, nm_file);
	if (check_plyr(*game) == 0)
		err_plyr(game, nm_file);
	if (check_ext_nb(*game) == 0)
		err_ext(game, nm_file);
	if (check_var(*game) == 0)
		err_var(game, nm_file);
	if (check_wall(game) != 0)
		err_wall(game, nm_file);
	get_all_colls(game);
	get_plyr_pos(game);
	get_ext_pos(game);
	check_is_valid_path(game);
}
