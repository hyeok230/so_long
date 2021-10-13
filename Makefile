# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junylee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 17:04:14 by junylee           #+#    #+#              #
#    Updated: 2021/10/13 16:37:43 by junylee          ###   ########.fr        #
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

SRCS_B	= $(D_B)main_bonus.c\
		  $(D_B)ft_itoa_bonus.c\
		  $(D_B)put_images_bonus.c\

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
