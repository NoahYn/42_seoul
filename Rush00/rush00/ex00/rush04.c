/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoonpa <jihoonpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:16:34 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/28 20:45:07 by jihoonpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c0, char c1, char c2, int x);

void	rush(int x, int y)
{	
	int	height;

	height = y;
	if (x == 0)
	{
		return ;
	}
	while (height > 0)
	{
		if (y == height)
		{
			ft_putchar('A', 'B', 'C', x);
		}
		else if (height == 1)
		{
			ft_putchar('C', 'B', 'A', x);
		}
		else
		{
			ft_putchar('B', ' ', 'B', x);
		}
		height--;
		write(1, "\n", 1);
	}
}
