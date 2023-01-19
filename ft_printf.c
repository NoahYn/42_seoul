/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:01:50 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/19 14:00:05 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putui_fd(unsigned int u, int fd)
{
	char	c;

	if (u >= 10)
		ft_putui_fd(u / 10, fd);
	c = u % 10 + '0';
	write(fd, &c, 1);
}

static void	ft_puthex_fd(unsigned long n, char format, int fd)
{
	char	c;

	if (format == 'p')
	{
		write(fd, "0x", 2);
		format = 'x';
	}
	if (n >= 16)
		ft_puthex_fd(n / 16, format, fd);
	c = ft_toupper("0123456789abcdef"[n % 16]);
	write (fd, &c, 1);
}

static void	handle_format(const char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == '%')
		write(1, "%%", 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_putui_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'p' || c == 'x' || c == 'X')
		ft_puthex_fd(va_arg(ap, unsigned long long), c, 1);
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
			handle_format(s[++i], ap);
			++i;
		}
		else
			write(1, &s[i++], 1);
	}
	va_end(ap);
	return (i);
}
