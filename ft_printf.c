/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:01:50 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/17 17:28:56 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write
#include <stdlib.h> // malloc, free
#include <stdarg.h> // va_start, va_arg, va_copy, va_end
#include <stdio.h> // printf("%d", )

#include "libft/libft.h"

static void	ft_putui_fd(unsigned int u, int fd)
{
	char	c;

	if (u >= 10)
		ft_putnbr_fd(u / 10, fd);
	c = u % 10 + '0';
	write(fd, &c, 1);
}

static void	ft_putptr_fd(unsigned int p, int fd)
{
	int		i;
	char	addr[16];

	write(1, "0x", 2);
	i = 0;
	while (i < 16)
	{
		if (p == 0)
			addr[i] = '0';
		else
			addr[i] = "0123456789abcdef"[p % 16];
		p /= 16;
		++i;
	}
	while (i-- > 0)
		write(1, &addr[i], 1);
}

static void	handle_format(const char *s, int i, va_list ap)
{
	void	*arg;

	if (s[i] == 'c')
		write(1, va_arg(ap, char), 1);
	else if (s[i] == '%')
		write(1, "%%", 1);
	else if (s[i] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (s[i] == 'u')
		ft_putui_fd(va_arg(ap, unsigned int), 1);

		
	else if (s[i] == 'p')
		ft_putptr_fd(va_arg(ap, void *), 1);
	else if (s[i] == 'x')
		va_arg(ap, int); // hexademical(base 16)				
	else if (s[i] == 'X')
		va_arg(ap, int); // hexademical uppercase
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			handle_format(s, ++i, ap);
			++i;
		}
		write(1, &s[i++], 1);
	}
	va_end(ap);
	return (i);
}
