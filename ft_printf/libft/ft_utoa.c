/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:23:36 by sunyoon           #+#    #+#             */
/*   Updated: 2023/02/10 13:28:24 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(unsigned int u)
{
	int	len;

	len = 1;
	while (u / 10)
	{
		++len;
		u /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int u)
{
	char	*result;
	int		len;

	len = ft_numlen(u);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	while (len--)
	{
		result[len] = u % 10 + '0';
		u /= 10;
	}
	return (result);
}
