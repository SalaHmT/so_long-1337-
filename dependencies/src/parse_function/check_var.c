/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:05:19 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/19 15:52:21 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_var(t_mlx_c game)
{
	int	i;
	int	ex;
	int	py;
	int	co;

	i = 0;
	py = 0;
	ex = 0;
	co = 0;
	while (game.map.map[i])
	{
		if (ft_strchr_i(game.map.map[i], 'E') == 1)
			ex = 1;
		if (ft_strchr_i(game.map.map[i], 'P') == 1)
			py = 1;
		if (ft_strchr_i(game.map.map[i], 'C') == 1)
			co = 1;
		i++;
	}
	return (py && ex && co);
}
