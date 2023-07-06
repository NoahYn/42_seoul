/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:01:50 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 17:01:14 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

static int	parse_format(const char format, va_list ap)
{
	unsigned char	c;
	int				num;

	if (format == 'c')
	{
		c = (unsigned char)(va_arg(ap, int));
		return (write(1, &c, 1));
	}
	else if (format == '%')
		return (write(1, "%%", 1));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_putui(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), format));
	else if (format == 'p')
	{
		num = 0;
		ft_putaddr(va_arg(ap, unsigned long long), &num);
		return (num);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		temp;

	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			temp = parse_format(s[++i], ap);
			++i;
		}
		else
			temp = write(1, &s[i++], 1);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	va_end(ap);
	return (count);
}
