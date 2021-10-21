/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:40:21 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:48:07 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(t_info *info)
{
	(void)info;
	exit(0);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C'
		|| c == 'E' || c == 'P' || c == 'Z')
		return (1);
	return (0);
}

void	print_end(char *str, int len)
{
	write(1, str, len);
	exit(1);
}
