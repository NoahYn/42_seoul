/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:41:43 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/02 18:59:44 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *restrict dst, char *restrict src,
	unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	d_len = 0;
	while (dst[d_len])
		d_len++;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	while (src[i] && i + d_len + 1 < dstsize)
		dst[d_len + i] = src[i++];
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
