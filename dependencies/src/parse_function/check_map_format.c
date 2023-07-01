/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:44:32 by shamsate          #+#    #+#             */
/*   Updated: 2023/07/01 14:47:55 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_map_format(t_mlx_c game)
{
	int		rw;
	int		len_ln;
	int		len;
	size_t	l;

	rw = -1;
	len_ln = ft_strlen_c(game.map.map[++rw]);
	while (game.map.map[rw])
	{
		len = ft_strlen_c(game.map.map[rw]);
		if (!game.map.map[rw + 1])
			break ;
		if (len_ln != len)
			return (1);
		rw++;
	}
	if ((len_ln - 1) != (int)ft_strlen_c(game.map.map[rw]))
		return (1);
	l = ft_strlen_c(game.map.map[rw - 1]);
	if (game.map.map[rw][--l] == '\n')
		return (1);
	return (0);
}
