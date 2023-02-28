/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:12 by sunyoon           #+#    #+#             */
/*   Updated: 2023/02/28 14:13:32 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strldup(const char *src, size_t size)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	if (len > size)
		len = size;
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	dst[len] = '\0';
	while (len--)
		dst[len] = src[len];
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;

	if (!dst && !src)
		return (dst);
	dst2 = dst;
	while (n--)
		*(dst2++) = *((unsigned char *)src++);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t n)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = n;
	strjoin = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoin)
		return (0);
	ft_memcpy(strjoin, s1, len_s1);
	ft_memcpy(strjoin + len_s1, s2, len_s2);
	strjoin[len_s1 + len_s2] = 0;
	return (strjoin);
}