/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:09:56 by shamsate          #+#    #+#             */
/*   Updated: 2023/07/01 14:56:00 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	contain(char c)
{
	char	*str;
	int		i;

	i = -1;
	str = "10PEC";
	while (str[++i])
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

int	check_char(t_mlx_c game)
{
	int	rw;
	int	cl;
	int	ply;

	ply = 0;
	rw = -1;
	while (game.map.map[++rw] != NULL)
	{
		cl = -1;
		while (game.map.map[rw][++cl] != '\n' && game.map.map[rw][cl] != '\0')
		{
			if (game.map.map[rw][cl] == 'P')
				ply++;
			if (!contain(game.map.map[rw][cl]))
				return (0);
			if (ply > 1)
				return (2);
		}
	}
	return (1);
}
