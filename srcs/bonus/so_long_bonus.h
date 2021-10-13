/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:22:21 by junylee           #+#    #+#             */
/*   Updated: 2021/10/13 16:40:31 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
}	t_enemy;

typedef struct s_img
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
}	t_img;

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
}	t_info;

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define ROW 11
# define COL 15
# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/*
** =============================================================================
** Utils
** =============================================================================
*/

char	*ft_itoa(int n);
void	load_images(t_info *info, int img_width, int img_height);
void	load_images2(t_info *info, int img_width, int img_height);
void	load_images3(t_info *info, int img_width, int img_height);

#endif
