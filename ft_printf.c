/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:01:50 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/20 23:49:51 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (format == 'p')
		ft_putaddr(va_arg(ap, unsigned long long), &count);
	else if (format == 'x' || format == 'X')
		ft_puthex(va_arg(ap, unsigned int), format, &count);
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
