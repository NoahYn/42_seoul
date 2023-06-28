/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:40:45 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 16:48:31 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putaddr(unsigned long long n, int *num)
{
	char	c;
	int		temp;

	if (*num == 0)
		*num += write(1, "0x", 2);
	if (*num == -1)
		return ;
	++(*num);
	if (n > 15)
		ft_putaddr(n / 16, num);
	c = "0123456789abcdef"[n % 16];
	temp = write(1, &c, 1);
	if (temp == -1)
		*num = -1;
}
