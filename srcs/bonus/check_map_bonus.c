/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:31:29 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:32:33 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_char(t_info *info, int i, int j)
{
	if (!is_valid_char(info->map[i][j]))
		print_end(
			"Map must be composed of only 0, 1, C, E, P, Z\n", 46);
	if (i == 0 || i == info->map_height - 1
		|| j == 0 || j == info->map_width - 1)
	{
		if (info->map[i][j] != '1')
			print_end("Map is not surrounded by wall\n", 30);
	}
}

void	init_ready(t_ready *ready)
{
	ready->player = 0;
	ready->enemy = 0;
	ready->coin = 0;
	ready->end = 0;
}

void	check_equipped(t_info *info, int i, int j, t_ready *ready)
{
	if (info->map[i][j] == 'P')
		ready->player++;
	else if (info->map[i][j] == 'Z')
		ready->enemy++;
	else if (info->map[i][j] == 'C')
		ready->coin++;
	else if (info->map[i][j] == 'E')
		ready->end++;
}

void	check_ready(t_ready ready)
{
	if (ready.player != 1)
		print_end("Map must have 1 player\n", 23);
	if (ready.enemy != 1)
		print_end("Map must have 1 enemy\n", 22);
	if (ready.coin == 0)
		print_end("Map must have at least 1 coin\n", 30);
	if (ready.end == 0)
		print_end("Map must have at least 1 end\n", 29);
}

void	check_map(t_info *info)
{
	t_ready	ready;
	int		i;
	int		j;

	i = 0;
	init_ready(&ready);
	while (i < info->map_height)
	{
		j = 0;
		if (ft_strlen(info->map[i]) != info->map_width)
			print_end("Not a square map\n", 17);
		while (j < info->map_width)
		{
			check_char(info, i, j);
			check_equipped(info, i, j, &ready);
			j++;
		}
		i++;
	}
	check_ready(ready);
}
