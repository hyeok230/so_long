/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:45:08 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 16:45:33 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_direction(t_info *info)
{
	if (info->enemy.direction == KEY_W)
		info->enemy.direction = KEY_D;
	else if (info->enemy.direction == KEY_A)
		info->enemy.direction = KEY_W;
	else if (info->enemy.direction == KEY_S)
		info->enemy.direction = KEY_A;
	else if (info->enemy.direction == KEY_D)
		info->enemy.direction = KEY_S;
}

void	move_enemy(t_info *info)
{
	if (check_wall_end_coin(info))
	{
		draw_tile(info, info->enemy.x, info->enemy.y);
		info->map[info->enemy.y][info->enemy.x] = '0';
		if (info->enemy.direction == KEY_W)
			info->enemy.y -= 1;
		else if (info->enemy.direction == KEY_A)
			info->enemy.x -= 1;
		else if (info->enemy.direction == KEY_S)
			info->enemy.y += 1;
		else if (info->enemy.direction == KEY_D)
			info->enemy.x += 1;
		info->map[info->enemy.y][info->enemy.x] = 'Z';
		(info->e_movement++);
	}
	else
		change_direction(info);
	draw_enemy(info);
}

void	move_delay(t_info *info)
{
	int	i;

	if (info->coins <= 0)
	{
		i = 0;
		while (i < 100000000)
			i++;
	}
}

int	sprite(t_info *info)
{
	static int	cnt = 0;

	if (cnt < 30)
	{
		draw_map2(info, cnt);
		cnt++;
	}
	else if (cnt < 60)
	{
		draw_map2(info, cnt);
		cnt++;
	}
	else
		cnt = 0;
	if (cnt == 1)
	{
		move_delay(info);
		move_enemy(info);
	}
	return (0);
}
