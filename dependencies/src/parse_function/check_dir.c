/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:25:34 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/24 17:26:10 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	check_dir(char	*nm_file)
{
	int	fd;

	fd = open(nm_file, O_DIRECTORY);
	if (fd != -1)
	{
		ft_printf(" So_Long : Error in Reading  ... Path.. :( \n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}
