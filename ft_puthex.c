/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:39:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/20 23:43:53 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char format, int *num)
{
	char	c;

	++(*num);
	if (n >= 16)
		ft_puthex(n / 16, format, num);
	c = "0123456789abcdef"[n % 16];
	if (format == 'X')
		c = ft_toupper(c);
	write(1, &c, 1);
}