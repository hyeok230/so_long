/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:32:36 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 15:41:13 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
}

void	load_images2(t_info *info, int img_width, int img_height)
{
	info->img.enemy_w1 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_w.xpm", &img_width, &img_height);
	info->img.enemy_w2 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_w2.xpm", &img_width, &img_height);
	info->img.enemy_a1 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_a.xpm", &img_width, &img_height);
	info->img.enemy_a2 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_a2.xpm", &img_width, &img_height);
	info->img.enemy_s1 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_s.xpm", &img_width, &img_height);
	info->img.enemy_s2 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_s2.xpm", &img_width, &img_height);
	info->img.enemy_d1 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_d.xpm", &img_width, &img_height);
	info->img.enemy_d2 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/Skel_d2.xpm", &img_width, &img_height);
}

void	load_images3(t_info *info, int img_width, int img_height)
{
	info->img.coin1 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest.xpm", &img_width, &img_height);
	info->img.coin2 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest2.xpm", &img_width, &img_height);
	info->img.coin3 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest3.xpm", &img_width, &img_height);
	info->img.coin4 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest4.xpm", &img_width, &img_height);
	info->img.coin5 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest5.xpm", &img_width, &img_height);
	info->img.coin6 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest6.xpm", &img_width, &img_height);
	info->img.end = mlx_xpm_file_to_image(info->mlx,
			"./img/map/End.xpm", &img_width, &img_height);
	if (info->img.end == NULL)
		print_end("end image error\n", 16);
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
	if (info->img.coin2 == NULL)
		print_end("coin2 image error\n", 18);
}

void	check_images2(t_info *info)
{
	if (info->img.coin3 == NULL)
		print_end("coin3 image error\n", 18);
	if (info->img.coin4 == NULL)
		print_end("coin4 image error\n", 18);
	if (info->img.coin5 == NULL)
		print_end("coin5 image error\n", 18);
	if (info->img.coin6 == NULL)
		print_end("coin6 image error\n", 18);
	if (info->img.enemy_w1 == NULL)
		print_end("enemy_w1 image error\n", 21);
	if (info->img.enemy_w2 == NULL)
		print_end("enemy_w2 image error\n", 21);
	if (info->img.enemy_a1 == NULL)
		print_end("enemy_a1 image error\n", 21);
	if (info->img.enemy_a2 == NULL)
		print_end("enemy_a2 image error\n", 21);
	if (info->img.enemy_s1 == NULL)
		print_end("enemy_s1 image error\n", 21);
	if (info->img.enemy_s2 == NULL)
		print_end("enemy_s2 image error\n", 21);
	if (info->img.enemy_d1 == NULL)
		print_end("enemy_d1 image error\n", 21);
	if (info->img.enemy_d2 == NULL)
		print_end("enemy_d2 image error\n", 21);
}
