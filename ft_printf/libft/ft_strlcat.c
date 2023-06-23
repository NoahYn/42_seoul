/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:41:43 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 12:27:53 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (dst[d_len])
		++d_len;
	s_len = 0;
	while (src[s_len])
		++s_len;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	i = 0;
	while (src[i] && i + d_len + 1 < dstsize)
	{
		dst[d_len + i] = src[i];
		++i;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
