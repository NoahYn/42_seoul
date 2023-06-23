/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:18:23 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 12:27:53 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dst;

	len = 0;
	while (src[len])
		++len;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	dst[len] = '\0';
	while (len--)
		dst[len] = src[len];
	return (dst);
}
