/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:17:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/09 17:09:44 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;

	if (!dst && !src)
		return (dst);
	dst2 = dst;
	if (src >= dst)
		while (len--)
			*(dst2++) = *((unsigned char *)src++);
	else
		while (len--)
			*(dst2 + len) = *((unsigned char *)src + len);
	return (dst);
}
