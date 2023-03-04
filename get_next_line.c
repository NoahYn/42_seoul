/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:00 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/04 22:23:16 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*del_fdnode(t_fdnode **list, t_fdnode *node, char *line)
{
	t_fdnode	*temp;

	if (node == 0)
		return (line);
	if (*list == node)
	{
		*list = node->next;
		free(node);
		return (line);
	}
	temp = *list;
	while (temp)
	{
		if (temp->next == node)
		{
			temp->next = node->next;
			free(node);
			return (line);
		}
		temp->next = temp;
	}
	return (line);
}

static t_fdnode	*set_fdnode(int fd)
{
	t_fdnode	*node;

	node = (t_fdnode *)malloc(sizeof(t_fdnode));
	if (!node)
		return (0);
	node->fd = fd;
	node->n = 0;
	node->bf[0] = 0;
	node->next = 0;
	return (node);
}

static t_fdnode	*get_fdnode(t_fdnode **list, int fd)
{
	t_fdnode	*node;

	if (!*list)
	{
		*list = set_fdnode(fd);
		return (*list);
	}
	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		if (node->next == 0)
		{
			node->next = set_fdnode(fd);
			return (node->next);
		}
		node = node->next;
	}
	return (0);
}

int	_read(t_fdnode *node, char **line)
{
	if (node->bf[0] != 0)
		return (1);
	node->n = read(node->fd, node->bf, BUFFER_SIZE);
	if (node->n == -1)
		*line = 0;
	if (node->n <= 0)
		return (0);
	node->bf[node->n] = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fdnode	*head;
	t_fdnode		*nd;
	char			*line;

	nd = get_fdnode(&head, fd);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || !nd)
		return (del_fdnode(&head, nd, 0));
	line = 0;
	while (1)
	{
		if (!_read(nd, &line))
			return (del_fdnode(&head, nd, line));
		nd->n = _ft_strchr(nd->bf, '\n');
		line = _ft_strjoin(line, nd->bf, nd->n);
		if (!line)
			return (del_fdnode(&head, nd, 0));
		if (nd->n)
		{
			if (ft_strlen(nd->bf + nd->n))
				ft_memcpy(nd->bf, &(nd->bf[nd->n]), BUFFER_SIZE - nd->n +1);
			else
				nd->bf[0] = 0;
			return (line);
		}
		nd->bf[0] = 0;
	}
}
