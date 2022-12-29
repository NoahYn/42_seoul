/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:58:12 by sunyoon           #+#    #+#             */
/*   Updated: 2022/12/29 15:22:44 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *restrict dst, const void *restrict src, unsigned int n)
{
	char	*dst2;
	char	*src2;

	dst2 = dst;
	src2 = src;
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}
