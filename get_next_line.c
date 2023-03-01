/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:00 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/01 22:11:55 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*del_fdNode(t_fdNode **list, t_fdNode *node)
{
	t_fdNode	*head;

	head = *list;
	if (head == node)
	{
		*list = node->next;
		free(node);
		return (0);
	}
	while (head)
	{
		if (head->next == node)
		{
			head->next = node->next;
			free(node);
			return (0);
		}
		head->next = head;
	}
	return (0);
}

static t_fdNode	*set_fdNode(int fd)
{
	t_fdNode	*node;
	
	node = (t_fdNode *)malloc(sizeof(t_fdNode));
	if (!node)
		return (0);
	node->fd = fd;
	node->count = 0;
	node->buff[0] = 0;
	node->next = 0;
	return (node);
}

static t_fdNode	*get_fdNode(t_fdNode **list, int fd) {
	t_fdNode	*node;

	if (!*list)
	{
		*list = set_fdNode(fd);
		return (*list);
	}
	node = *list;
	while (node)
	{
		if (node->fd == fd) {
			return (node);
		}
		if (node->next == 0) {
			node->next = set_fdNode(fd);
			return (node->next);
		}
		node = node->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fdNode *head;
	t_fdNode		*node;
	char			*line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || !get_fdNode(&head, fd))
		return (0);
	node = get_fdNode(&head, fd);
	line = 0;
	while (1)
	{
		if (node->buff[0] == 0)
		{
			node->count = read(node->fd, node->buff, BUFFER_SIZE);
			if (node->count == -1) // read_count == -1
				return (del_fdNode(&head, node));
			else if (node->count == 0) // EOF	
			{
				del_fdNode(&head, node);
				return (line);
			}
			node->buff[node->count] = 0;
		}
		node->count = _ft_strchr(node->buff, '\n');
		line = _ft_strjoin(line, node->buff, node->count);
		if (!line)
			return (del_fdNode(&head, node));
		if (!node->count)	// can't find '\n', keep going
			node->buff[0] = 0;
		else 
		{
			if (ft_strlen(node->buff + node->count))
				ft_memcpy(node->buff, &(node->buff[node->count]), BUFFER_SIZE - node->count + 1);
			else
				node->buff[0] = 0;
			return (line);
		}
	}
}
