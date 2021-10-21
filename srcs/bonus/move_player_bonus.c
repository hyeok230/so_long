/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:00 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:39:16 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movement(t_info *info)
{
	char	*itoa;

	itoa = ft_itoa(info->movement);
	mlx_string_put(info->mlx, info->win, info->player.x * 50 + 15,
		info->player.y * 50 + 15, 0xFFFFFF, itoa);
	free(itoa);
}

void	move_player(t_info *info, int keycode)
{
	if (check_end(keycode, info))
		print_end("success!\n", 9);
	if (check_enemy(keycode, info))
		print_end("you lose.\n", 10);
	if (check_coin(keycode, info))
		(info->coins)--;
	if (!(check_wall(keycode, info)))
	{
		draw_tile(info, info->player.x, info->player.y);
		info->map[info->player.y][info->player.x] = '0';
		if (keycode == KEY_W)
			info->player.y -= 1;
		else if (keycode == KEY_A)
			info->player.x -= 1;
		else if (keycode == KEY_S)
			info->player.y += 1;
		else if (keycode == KEY_D)
			info->player.x += 1;
		info->map[info->player.y][info->player.x] = 'P';
		(info->movement++);
	}
	draw_player(info, keycode);
	print_movement(info);
}

int	deal_key(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(info, keycode);
	return (0);
}
