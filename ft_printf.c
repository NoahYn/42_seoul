/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:01:50 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/19 17:12:09 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr(char *s, int *num)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	*num += write(1, s, len);
}

static void	ft_putnbr(int n, int *num)
{
	char	c;

	++(*num);
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
	if (n >= 10)
		ft_putnbr(n / 10, num);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void	ft_putui(unsigned int u, int *num)
{
	char	c;

	++(*num);
	if (u > 9)
		ft_putui(u / 10, num);
	c = u % 10 + '0';
	write(1, &c, 1);
}

static void	ft_puthex(unsigned long n, char format, int *num)
{
	char	c;

	++(*num);
	if (format == 'p')
	{
		*num += write(1, "0x", 2);
		format = 'x';
	}
	if (n >= 16)
		ft_puthex(n / 16, format, num);
	c = ft_toupper("0123456789abcdef"[n % 16]);
	write(1, &c, 1);
}

static int	parse_format(const char format, va_list ap)
{
	int				count;
	unsigned char	c;

	count = 0;
	if (format == 'c')
	{
		c = (unsigned char)(va_arg(ap, int));
		count += write(1, &c, 1);
	}
	else if (format == '%')
		count += write(1, "%%", 1);
	else if (format == 's')
		ft_putstr(va_arg(ap, char *), &count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ap, int), &count);
	else if (format == 'u')
		ft_putui(va_arg(ap, unsigned int), &count);
	else if (format == 'p' || format == 'x' || format == 'X')
		ft_puthex(va_arg(ap, unsigned long long), c, &count);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += parse_format(s[++i], ap);
			++i;
		}
		else
			count += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (count);
}
