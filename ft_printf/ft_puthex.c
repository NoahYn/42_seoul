/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:39:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/02/10 13:34:52 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	char	*hex;
	int		temp;
	int		i;

	hex = ft_htoa(n);
	if (hex == 0)
		return (-1);
	if (format == 'X')
	{
		i = 0;
		while (hex[i])
		{
			hex[i] = ft_toupper(hex[i]);
			++i;
		}
	}
	temp = write(1, hex, ft_strlen(hex));
	free(hex);
	return (temp);
}
