/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:41:27 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 16:40:09 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int	len;
	int	num;

	if (!s)
	{
		num = write(1, "(null)", 6);
		return (num);
	}
	len = 0;
	while (s[len])
		++len;
	num = write(1, s, len);
	return (num);
}
