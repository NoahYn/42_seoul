/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:23:36 by sunyoon           #+#    #+#             */
/*   Updated: 2023/02/10 13:30:31 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 16)
	{
		++len;
		n /= 16;
	}
	return (len);
}

char	*ft_htoa(unsigned int h)
{
	char	*result;
	int		len;

	len = ft_numlen(h);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	while (len--)
	{
		result[len] = "0123456789abcdef"[h % 16];
		h /= 16;
	}
	return (result);
}
