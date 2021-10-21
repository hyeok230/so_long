/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:08:08 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:09:46 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_enemy1(t_info *info, int x, int y)
{
	if (info->enemy.direction == KEY_W)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_w1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (info->enemy.direction == KEY_A)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_a1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (info->enemy.direction == KEY_S)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_s1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (info->enemy.direction == KEY_D)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_d1,
			x * 50 + 10, y * 50 + 10);
	}
}

void	draw_enemy2(t_info *info, int x, int y)
{
	if (info->enemy.direction == KEY_W)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_w2,
			x * 50 + 10, y * 50 + 10);
	}
	else if (info->enemy.direction == KEY_A)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_a2,
			x * 50 + 10, y * 50 + 10);
	}
	else if (info->enemy.direction == KEY_S)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_s2,
			x * 50 + 10, y * 50 + 10);
	}
	else if (info->enemy.direction == KEY_D)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.enemy_d2,
			x * 50 + 10, y * 50 + 10);
	}
}

void	draw_enemy(t_info *info)
{
	draw_tile(info, info->enemy.x, info->enemy.y);
	if (info->e_movement % 2 == 0)
		draw_enemy1(info, info->enemy.x, info->enemy.y);
	else
		draw_enemy2(info, info->enemy.x, info->enemy.y);
}
