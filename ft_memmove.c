/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:17:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/05 15:35:15 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (src >= dst)
		while (len--)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
	else
		while (len--)
			*((unsigned char *)dst--) = *((unsigned char *)src--);
	return (dst);
}
