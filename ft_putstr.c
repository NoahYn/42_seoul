/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:41:27 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/20 23:43:04 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s, int *num)
{
	int	len;

	if (!s)
	{
		*num += write(1, "(null)", 6);
		return ;
	}
	len = 0;
	while (s[len])
		++len;
	*num += write(1, s, len);
}