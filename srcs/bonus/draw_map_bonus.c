/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:00:19 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:01:06 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_tile(t_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img.tile,
		x * 50, y * 50);
}

void	draw_wall(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.wall,
		x * 50, y * 50);
}

void	draw_coin(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.coin1,
		x * 50 + 10, y * 50 + 10);
}

void	draw_end(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.end,
		x * 50 + 10, y * 50 + 10);
}

void	draw_img(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		draw_wall(info, j, i);
	else if (info->start == 0 && info->map[i][j] == '0')
		draw_tile(info, j, i);
	else if (info->start == 0 && info->map[i][j] == 'P')
	{
		draw_tile(info, j, i);
		info->player.x = j;
		info->player.y = i;
	}
	else if (info->start == 0 && info->map[i][j] == 'C')
	{
		draw_coin(info, j, i);
		(info->coins)++;
	}
	else if (info->map[i][j] == 'E')
		draw_end(info, j, i);
	else if (info->start == 0 && info->map[i][j] == 'Z')
	{
		draw_tile(info, j, i);
		info->enemy.x = j;
		info->enemy.y = i;
		info->enemy.direction = KEY_S;
	}
}
