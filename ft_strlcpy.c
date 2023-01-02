/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:48:21 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/02 18:55:40 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *restrict dst, char *restrict src,
	unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	len;

	if (!dst || !src)
		return (0);
	i = 0;
	len = 0;
	while (src[len])
		len++;
	while (i < len && i + 1 < dstsize)
		dst[i++] = src[i++];
	if (dstsize > 0)
		dst[i] = '\0';
	return (len);
}
