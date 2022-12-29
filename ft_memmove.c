/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:17:29 by sunyoon           #+#    #+#             */
/*   Updated: 2022/12/29 15:47:15 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char	*dst2;
	char	*src2;

	if (src >= dst)
	{
		dst2 = dst;
		src2 = src;
		while (len--)
			*dst2++ = *src2++;
	}
	else
	{
		dst2 = dst + len;
		src2 = src + len;
		while (len--)
			*dst2-- = *src2--;
	}
	return (dst);
}
