/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:04:41 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:05:18 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player1(t_info *info, int x, int y, int keycode)
{
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_w1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_a1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_S)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_s1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_D)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_d1,
			x * 50 + 10, y * 50 + 10);
	}
}

void	draw_player2(t_info *info, int x, int y, int keycode)
{
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_w2,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_a2,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_S)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_s2,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_D)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_d2,
			x * 50 + 10, y * 50 + 10);
	}
}

void	draw_player(t_info *info, int keycode)
{
	draw_tile(info, info->player.x, info->player.y);
	if (info->movement % 2 == 0)
		draw_player1(info, info->player.x, info->player.y, keycode);
	else
		draw_player2(info, info->player.x, info->player.y, keycode);
}
