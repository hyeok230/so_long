# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junylee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 17:04:14 by junylee           #+#    #+#              #
#    Updated: 2021/10/21 17:35:56 by junylee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Command Variables
# =============================================================================

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -Imlx
OPTIONS 	= -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
NAME		= so_long

# =============================================================================
# File Variables
# =============================================================================

FOLDER	= ./srcs/
D_M		= mandatory/
D_B		= bonus/

SRCS	= $(D_M)main.c\
		  $(D_M)check_map.c\
		  $(D_M)draw_player.c\
		  $(D_M)get_next_line.c\
		  $(D_M)move_player.c\
		  $(D_M)draw_map.c\
		  $(D_M)ft_itoa.c\
		  $(D_M)load_map.c\
		  $(D_M)move_check.c\
		  $(D_M)put_images.c\
		  $(D_M)utils.c\

SRCS_B	= $(D_B)main_bonus.c\
		  $(D_B)ft_itoa_bonus.c\
		  $(D_B)put_images_bonus.c\
		  $(D_B)get_next_line_bonus.c\
		  $(D_B)draw_enemy_bonus.c\
		  $(D_B)draw_player_bonus.c\
		  $(D_B)draw_map_bonus.c\
		  $(D_B)check_map_bonus.c\
		  $(D_B)load_map_bonus.c\
		  $(D_B)move_player_bonus.c\
		  $(D_B)sprite2_bonus.c\
		  $(D_B)sprite_bonus.c\
		  $(D_B)move_check_bonus.c\
		  $(D_B)utils_bonus.c\

SOURCES =  $(addprefix $(FOLDER), $(SRCS))
SOURCES_BONUS = $(addprefix $(FOLDER), $(SRCS_B))

OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)

# =============================================================================
# Target Generating
# =============================================================================

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS_BONUS)

.PHONY: all clean fclean re bonus
