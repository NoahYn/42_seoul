/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:23:36 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 18:28:13 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		++len;
	while (n / 10)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	len = ft_numlen(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	if (n < 0)
	{
		result[--len] = (n % 10) * (-1) + '0';
		n /= -10;
		sign = -1;
	}
	while (len--)
	{
		result[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
