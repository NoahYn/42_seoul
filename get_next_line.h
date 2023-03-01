/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:23 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/01 21:13:16 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_fdNode {
	int fd;
	int count;
	char buff[BUFFER_SIZE + 1];
	struct s_fdNode *next;
	//struct s_fdNode *prev;
} t_fdNode;

//static function
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*_ft_strjoin(char *s1, char const *s2, size_t n);
size_t	ft_strlen(const char *s);
int		_ft_strchr(const char *s, int c);

#endif
