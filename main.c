/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:27 by junylee           #+#    #+#             */
/*   Updated: 2021/10/07 21:20:33 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
# include <stdio.h>
#include <stdlib.h>

# define ROW 11
# define COL 15
# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct	s_player
{
	int	x;
	int	y;
} t_player;

typedef	struct	s_enemy
{
	int	x;
	int y;
	int direction;
} t_enemy;

typedef	struct	s_img
{
	void	*tile;
	void	*wall;
	void	*player_w1;
	void	*player_w2;
	void	*player_a1;
	void	*player_a2;
	void	*player_s1;
	void	*player_s2;
	void	*player_d1;
	void	*player_d2;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*enemy_w1;
	void	*enemy_w2;
	void	*enemy_a1;
	void	*enemy_a2;
	void	*enemy_s1;
	void	*enemy_s2;
	void	*enemy_d1;
	void	*enemy_d2;
	void	*end;
}		t_img;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			movement;
	int			e_movement;
	int			start;
	int			coins;
	t_player	player;
	t_enemy		enemy;
	char		**map;
	int			map_height;
	int			map_width;
}		t_info;

static int	num_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	num_length(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*out;
	int			len;

	len = num_length(n);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	out[len--] = '\0';
	if (n < 0)
	{
		out[0] = '-';
		n *= -1;
	}
	if (n == 0)
		out[len] = '0';
	while (n != 0)
	{
		out[len] = '0' + num_abs(n % 10);
		n /= 10;
		len--;
	}
	return (out);
}

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
	info->img.coin2 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest2.xpm", &img_width, &img_height);
}

void	load_images2(t_info *info, int img_width, int img_height)
{
	info->img.coin3 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest3.xpm", &img_width, &img_height);
	info->img.coin4 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest4.xpm", &img_width, &img_height);
	info->img.coin5 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest5.xpm", &img_width, &img_height);
	info->img.coin6 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/Chest6.xpm", &img_width, &img_height);
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
	info->img.end = mlx_xpm_file_to_image(info->mlx,
			"./img/map/End.xpm", &img_width, &img_height);
}

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
	int i;
	int j;

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

void	load_map(t_info *info, char *file)
{
	(void)info;
	(void)file;
}

void	check_map(t_info *info)
{
	(void)info;
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
	info->start = 0;
	info->coins = 0;
	load_images(info, 0, 0);
	load_images2(info, 0, 0);
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

int check_wall(int keycode, t_info *info)
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

int deal_key(int keycode, t_info *info)
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
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin1, 
				x * 50 + 10, y * 50 + 10);
	}
	else if (cnt < 20)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin2, 
				x * 50 + 10, y * 50 + 10);
	}
	else if (cnt < 30)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin3, 
				x * 50 + 10, y * 50 + 10);
	}
	else if (cnt < 40)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin4, 
				x * 50 + 10, y * 50 + 10);
	}
	else if (cnt < 50)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin5, 
				x * 50 + 10, y * 50 + 10);
	}
	else if (cnt < 60)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.coin6, 
				x * 50 + 10, y * 50 + 10);
	}
}

void	draw_map2(t_info *info, int cnt)
{
	int i;
	int j;
	
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
	if (info->map[y][x] == '1' || info->map[y][x] == 'E' || info->map[y][x] == 'C')
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

int		check_wall_end_coin(t_info *info)
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
	draw_enemy(info);
}

int	sprite(t_info *info)
{
	int i;
	static int cnt = 0;
	
	i = 0;
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
		if (info->coins <= 0)
		{
			i = 0;
			while(i < 100000000)
				i++;
		}
		move_enemy(info);
	}
	return (0);
}

int main(int argc, char **argv)
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
		while(j < COL)
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
