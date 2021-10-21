/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:42:32 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:44:00 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_coin2(t_info *info, int x, int y, int cnt)
{
	draw_tile(info, x, y);
	if (cnt < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin1,
			x * 50 + 10, y * 50 + 10);
	else if (cnt < 20)
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin2,
			x * 50 + 10, y * 50 + 10);
	else if (cnt < 30)
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin3,
			x * 50 + 10, y * 50 + 10);
	else if (cnt < 40)
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin4,
			x * 50 + 10, y * 50 + 10);
	else if (cnt < 50)
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin5,
			x * 50 + 10, y * 50 + 10);
	else if (cnt < 60)
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin6,
			x * 50 + 10, y * 50 + 10);
}

void	draw_map2(t_info *info, int cnt)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j] == 'C')
			{
				draw_coin2(info, j, i, cnt);
			}
			j++;
		}
		i++;
	}
}

int	is_wall_end_coin(t_info *info, int x, int y)
{
	if (info->map[y][x] == '1' || info->map[y][x] == 'E'
			|| info->map[y][x] == 'C')
		return (1);
	return (0);
}

void	is_player(t_info *info, int x, int y)
{
	if (info->map[y][x] == 'P')
	{
		print_end("you lose.\n", 10);
	}
}

int	check_wall_end_coin(t_info *info)
{
	if (info->enemy.direction == KEY_W)
	{
		is_player(info, info->enemy.x, info->enemy.y - 1);
		if (is_wall_end_coin(info, info->enemy.x, info->enemy.y - 1))
			return (0);
	}
	else if (info->enemy.direction == KEY_A)
	{
		is_player(info, info->enemy.x - 1, info->enemy.y);
		if (is_wall_end_coin(info, info->enemy.x - 1, info->enemy.y))
			return (0);
	}
	else if (info->enemy.direction == KEY_S)
	{
		is_player(info, info->enemy.x, info->enemy.y + 1);
		if (is_wall_end_coin(info, info->enemy.x, info->enemy.y + 1))
			return (0);
	}
	else if (info->enemy.direction == KEY_D)
	{
		is_player(info, info->enemy.x + 1, info->enemy.y);
		if (is_wall_end_coin(info, info->enemy.x + 1, info->enemy.y))
			return (0);
	}
	return (1);
}
