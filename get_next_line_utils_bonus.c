/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:12 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/05 11:05:32 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	_ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i++] == (char)c)
			return (i);
	}
	return (0);
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

char	*_ft_strjoin(char *s1, char const *s2, size_t n)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	if (n == 0)
		len_s2 = ft_strlen(s2);
	else
		len_s2 = n;
	strjoin = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoin)
	{
		free(s1);
		return (0);
	}
	ft_memcpy(strjoin, s1, len_s1);
	free(s1);
	ft_memcpy(strjoin + len_s1, s2, len_s2);
	strjoin[len_s1 + len_s2] = 0;
	return (strjoin);
}
