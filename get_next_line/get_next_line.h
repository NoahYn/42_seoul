/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:23 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/05 11:05:13 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4020
# endif

typedef struct s_fdnode {
	int				fd;
	int				n;
	char			bf[BUFFER_SIZE + 1];
	char			*line;
	struct s_fdnode	*next;
}	t_fdnode;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*_ft_strjoin(char *s1, char const *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	_ft_strchr(const char *s, int c);

#endif
