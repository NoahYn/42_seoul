/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:46:57 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/20 23:48:04 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n, int *num)
{
	char	c;

	if (n < 0)
	{
		*num += write(1, "-", 1);
		if (n == -2147483648)
		{
			*num += write(1, "2147483648", 10);
			return ;
		}
		n *= -1;
	}
	++(*num);
	if (n > 9)
		ft_putnbr(n / 10, num);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putui(unsigned int u, int *num)
{
	char	c;

	++(*num);
	if (u > 9)
		ft_putui(u / 10, num);
	c = u % 10 + '0';
	write(1, &c, 1);
}