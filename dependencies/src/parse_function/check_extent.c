/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:51:43 by shamsate          #+#    #+#             */
/*   Updated: 2023/06/17 21:57:22 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_extent(const char *str, const char *extention)
{
	size_t	extent_len;
	size_t	str_len;

	extent_len = ft_strlen_c(extention);
	str_len = ft_strlen_c(str);
	while (str_len > extent_len)
	{
		str++;
		str_len--;
	}
	return (ft_strcmp(str, extention));
}
