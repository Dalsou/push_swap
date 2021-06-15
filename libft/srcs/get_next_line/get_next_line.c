/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:54:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 15:12:58 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_and_return(char **str, int ret)
{
	if (ret == -1 || ret == 0)
	{
		free(*str);
		(*str) = NULL;
	}
	return (ret);
}

int	find_line(char **str, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *str;
	while (tmp[i])
	{
		if ((tmp[i]) == '\n')
		{
			if (i == 0)
				(*line) = ft_strdup("");
			else
				(*line) = ft_substr(*str, 0, i);
			if ((*line) == NULL)
				return (-1);
			tmp = ft_substr(*str, i + 1, ft_strlen(*str));
			if (!tmp)
				return (-1);
			free(*str);
			(*str) = tmp;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_error_and_str(char **str, char **line, int fd)
{
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ret = read(fd, *str, 0);
	if (ret == -1)
		return (-1);
	if (*str)
	{
		ret = find_line(str, line);
		return (ret);
	}
	else
	{
		*str = ft_strdup("");
		if (!(*str))
			return (-1);
	}
	return (0);
}

int	join_line(char **str, char *buff)
{
	char		*tmp;

	tmp = ft_strjoin(*str, buff);
	if (!tmp)
		return (-1);
	free(*str);
	*str = tmp;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ret = check_error_and_str(&str, line, fd);
	if (ret == 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		while (ret > 0)
		{
			buff[ret] = '\0';
			if (join_line(&str, buff) == -1)
				return (free_and_return(&str, -1));
			ret = find_line(&str, line);
			if (ret == 1 || ret == -1)
				return (free_and_return(&str, ret));
		}
		*line = ft_substr(str, 0, ft_strlen(str));
		if (!(*line))
			return (free_and_return(&str, -1));
	}
	return (free_and_return(&str, ret));
}
