/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:40:45 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/20 23:43:22 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putaddr(unsigned long long n, int *num)
{
	char	c;

	if (n == 0)
	{
		*num += write(1, "(nil)", 5);
		return ;
	}
	if (*num == 0)
		*num += write(1, "0x", 2);
	++(*num);
	if (n > 15)
		ft_putaddr(n / 16, num);
	c = "0123456789abcdef"[n % 16];
	write(1, &c, 1);
}
