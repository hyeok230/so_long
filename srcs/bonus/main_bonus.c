/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:27 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 17:23:30 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			draw_img(info, i, j);
			j++;
		}
		i++;
	}
	if (info->start == 0)
	{
		draw_player(info, KEY_S);
		draw_enemy(info);
		info->start = 1;
	}
}

void	init(t_info *info, char *file)
{
	load_map(info, file);
	check_map(info);
	info->mlx = mlx_init();
	info->movement = 0;
	info->e_movement = 0;
	info->win = mlx_new_window(info->mlx,
			50 * info->map_width, 50 * info->map_height, "so_long");
	if (info->mlx == NULL || info->win == NULL)
		print_end("mlx init or new window error\n", 29);
	info->start = 0;
	info->coins = 0;
	load_images(info, 0, 0);
	load_images2(info, 0, 0);
	load_images3(info, 0, 0);
	check_images(info);
	check_images2(info);
	info->enemy.x = -1;
	info->enemy.y = -1;
	draw_map(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		print_end("wrong args", 10);
	init(&info, argv[1]);
	mlx_hook(info.win, KEY_PRESS, 0, &deal_key, &info);
	mlx_hook(info.win, KEY_EXIT, 0, &ft_close, &info);
	mlx_loop_hook(info.mlx, &sprite, &info);
	mlx_loop(info.mlx);
}
