/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:07:42 by junylee           #+#    #+#             */
/*   Updated: 2021/10/21 15:22:23 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_first(char c, int i)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	if (!tmp)
		return (0);
	tmp[i] = c;
	return (tmp);
}

int	ft_strcat(char **str, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*str == 0)
	{
		tmp = ft_first(c, i);
		i++;
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 2));
		if (!tmp)
			return (0);
		while ((*str)[i])
		{
			tmp[i] = (*str)[i];
			i++;
		}
		tmp[i++] = c;
	}
	tmp[i] = '\0';
	free(*str);
	*str = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int		rd_out;
	char	buffer;

	*line = 0;
	buffer = 0;
	rd_out = read(fd, &buffer, 1);
	while (rd_out)
	{
		if (rd_out < 0)
			return (-1);
		if (buffer == '\n')
			return (1);
		if (ft_strcat(line, buffer) == 0)
			print_end("ft_strcat error\n", 16);
		rd_out = read(fd, &buffer, 1);
	}
	return (0);
}
