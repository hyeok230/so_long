/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:27 by junylee           #+#    #+#             */
/*   Updated: 2021/10/13 17:07:44 by junylee          ###   ########.fr       */
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

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	name_check(char *file)
{
	int len;

	len = ft_strlen(file);
}

void	load_map(t_info *info, char *file)
{
	name_check(file);
}

void	check_map(t_info *info)
{
	(void)info;
}

void	init(t_info *info, char *file)a
{
	load_map(info, file);
	check_map(info);
	info->mlx = mlx_init();
	info->movement = 0;
	info->e_movement = 0;
	info->win = mlx_new_window(info->mlx,
			50 * info->map_width, 50 * info->map_height, "so_long");
	info->start = 0;
	info->coins = 0;
	load_images(info, 0, 0);
	load_images2(info, 0, 0);
	load_images3(info, 0, 0);
	info->enemy.x = -1;
	info->enemy.y = -1;
	draw_map(info);
}

int	check_end(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (info->map[info->player.y - 1][info->player.x]
				== 'E' && info->coins <= 0)
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (info->map[info->player.y][info->player.x - 1]
				== 'E' && info->coins <= 0)
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (info->map[info->player.y + 1][info->player.x]
				== 'E' && info->coins <= 0)
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (info->map[info->player.y][info->player.x + 1]
				== 'E' && info->coins <= 0)
			return (1);
	}
	return (0);
}

int	check_enemy(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (info->map[info->player.y - 1][info->player.x] == 'Z')
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (info->map[info->player.y][info->player.x - 1] == 'Z')
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (info->map[info->player.y + 1][info->player.x] == 'Z')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (info->map[info->player.y][info->player.x + 1] == 'Z')
			return (1);
	}
	return (0);
}

int	check_coin(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (info->map[info->player.y - 1][info->player.x] == 'C')
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (info->map[info->player.y][info->player.x - 1] == 'C')
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (info->map[info->player.y + 1][info->player.x] == 'C')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (info->map[info->player.y][info->player.x + 1] == 'C')
			return (1);
	}
	return (0);
}

int	is_wall_or_end(t_info *info, int x, int y)
{
	if (info->map[y][x] == '1' || info->map[y][x] == 'E')
		return (1);
	return (0);
}

int	check_wall(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (is_wall_or_end(info, info->player.x, info->player.y - 1))
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (is_wall_or_end(info, info->player.x - 1, info->player.y))
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (is_wall_or_end(info, info->player.x, info->player.y + 1))
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (is_wall_or_end(info, info->player.x + 1, info->player.y))
			return (1);
	}
	return (0);
}

void	print_movement(t_info *info)
{
	char	*itoa;

	itoa = ft_itoa(info->movement);
	mlx_string_put(info->mlx, info->win, info->player.x * 50 + 15,
		info->player.y * 50 + 15, 0xFFFFFF, itoa);
	free(itoa);
}

void	print_end(char *str, int len)
{
	write(1, str, len);
	exit(1);
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

int	ft_close(t_info *info)
{
	(void)info;
	exit(0);
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

int	main(int argc, char **argv)
{
	t_info	info;
	char map[ROW][COL] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', 'C', '0', '0', '0', 'C', '0', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', 'C', '0', '1', '0', '0', '0', '1', '1', '0', '0', 'P', '1', '0', '1'},
		{'1', '0', '0', '0', '0', 'Z', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', 'C', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '1', '1', '1', '1', '1', 'C', '0', '0', '0', '0', 'C', '0', '0', '1'},
		{'1', '0', 'E', '0', '0', '0', 'C', '0', '0', 'C', '0', '0', '1', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	};
	info.map = (char**)malloc(sizeof(char*) * ROW);
	for (int i = 0; i < ROW; i++)
	{
		info.map[i] = (char*)malloc(sizeof(char) * COL);
	}
	int i = 0;
	int j;
	while (i < ROW)
	{
		j = 0;
		while (j < COL)
		{
			info.map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	info.map_height = ROW;
	info.map_width = COL;
	(void)argv;
	if (argc != 2)
		print_end("wrong args", 10);
	init(&info, argv[1]);
	mlx_hook(info.win, KEY_PRESS, 0, &deal_key, &info);
	mlx_hook(info.win, KEY_EXIT, 0, &ft_close, &info);
	mlx_loop_hook(info.mlx, &sprite, &info);
	mlx_loop(info.mlx);
}
