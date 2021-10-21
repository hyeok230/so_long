/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:01:16 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 17:21:35 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_info *info, int img_width, int img_height)
{
	info->img.tile = mlx_xpm_file_to_image(info->mlx,
			"./img/map/Grass.xpm", &img_width, &img_height);
	info->img.wall = mlx_xpm_file_to_image(info->mlx,
			"./img/map/Rock.xpm", &img_width, &img_height);
	info->img.player_w1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_w.xpm", &img_width, &img_height);
	info->img.player_w2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_w2.xpm", &img_width, &img_height);
	info->img.player_a1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_a.xpm", &img_width, &img_height);
	info->img.player_a2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_a2.xpm", &img_width, &img_height);
	info->img.player_s1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_s.xpm", &img_width, &img_height);
	info->img.player_s2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_s2.xpm", &img_width, &img_height);
	info->img.player_d1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_d.xpm", &img_width, &img_height);
	info->img.player_d2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/Char_d2.xpm", &img_width, &img_height);
	info->img.coin1 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest.xpm", &img_width, &img_height);
	info->img.end = mlx_xpm_file_to_image(info->mlx,
			"./img/map/End.xpm", &img_width, &img_height);
}

void	check_images(t_info *info)
{
	if (info->img.tile == NULL)
		print_end("tile image error\n", 17);
	if (info->img.wall == NULL)
		print_end("wall image error\n", 17);
	if (info->img.player_w1 == NULL)
		print_end("player_w1 image error\n", 22);
	if (info->img.player_w2 == NULL)
		print_end("player_w2 image error\n", 22);
	if (info->img.player_a1 == NULL)
		print_end("player_a1 image error\n", 22);
	if (info->img.player_a2 == NULL)
		print_end("player_a2 image error\n", 22);
	if (info->img.player_s1 == NULL)
		print_end("player_s1 image error\n", 22);
	if (info->img.player_s2 == NULL)
		print_end("player_s2 image error\n", 22);
	if (info->img.player_d1 == NULL)
		print_end("player_d1 image error\n", 22);
	if (info->img.player_d2 == NULL)
		print_end("player_d2 image error\n", 22);
	if (info->img.coin1 == NULL)
		print_end("coin1 image error\n", 18);
	if (info->img.end == NULL)
		print_end("end image error\n", 16);
}
