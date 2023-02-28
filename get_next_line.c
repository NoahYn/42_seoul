/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:00 by sunyoon           #+#    #+#             */
/*   Updated: 2023/02/28 14:13:29 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char **buff, char **next_line)
{
	if (*buff)
		free(*buff);
	if (*next_line)
		free(*next_line);
	return ;
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*temp;
	char		*line;
	int			num;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (0);
	if (save)
	{
		num = ft_strchr(save, '\n');
		if (num == -1) // can't find '\n'
		{
			line = ft_strldup(save, ft_strlen(save));
			if (!line)
				return (0);
		}
		else // find '\n'
		{
			line = ft_strldup(save, num);
			if (!line)
				return (0);
			if (ft_strlen(save + num + 1) == 0)
			{
				free(save);
				save = 0;
				return (line);
			}
			temp = ft_strldup(save + num + 1, ft_strlen(save + num + 1));
			if (!temp)
			{
				free(line);
				return (0);
			}
			free(save);
			save = temp;
			return (line);
		}
	}
	num = 1;
	while (num > 0)
	{
		temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
		{
			if (line)
				free(line);
			return (0);
		}
		num = read(fd, temp, BUFFER_SIZE);
		if (num == -1 || (num == 0 && !line))
		{
			free_ptr(&temp, &line);
			return (0);
		}
		if (num == 0)
			return (line);
		temp[num] = 0;
		if (ft_strchr(temp, '\n') != -1) // find
		{
			num = ft_strchr(temp, '\n');
			if (!line)
			{
				line = ft_strldup(temp, num + 1);
				if (!line)
				{
					free(temp);
					return (0);
				}
			}
			else
				ft_strjoin(line, temp, num);
			if (ft_strlen(temp + num + 1) > 0)
			{
				save = ft_strldup(temp + num + 1, ft_strlen(temp + num + 1));
				if (!save)
				{
					free_ptr(&temp, &line);
					return (0);
				}
			}
			free(temp);
			return (line);
		}
		if (!line)
		{
			line = ft_strldup(temp, num);
			if (!line)
			{
				free(temp);
				return (0);
			}
		}
		else
		{
			ft_strjoin(line, temp, num);
		}
		free(temp);
	}
	return (line);
}
