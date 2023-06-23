/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:46:57 by sunyoon           #+#    #+#             */
/*   Updated: 2023/02/10 13:34:39 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*nbr;
	int		temp;

	nbr = ft_itoa(n);
	if (nbr == 0)
		return (-1);
	temp = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (temp);
}

int	ft_putui(unsigned int u)
{
	char	*ui;
	int		temp;

	ui = ft_utoa(u);
	if (ui == 0)
		return (-1);
	temp = write(1, ui, ft_strlen(ui));
	free(ui);
	return (temp);
}
