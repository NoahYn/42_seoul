/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:29:56 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/01 18:17:21 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_rev_int_tab(int *num, int size);

void	ft_print_itoa(int *num, int size);

void	ft_putnbr(int nb)
{
	int	num[10];
	int	size;

	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		nb *= -1;
		write(1, "-", 1);
	}
	size = 0;
	while (nb > 0)
	{
		num[size] = nb % 10;
		nb /= 10;
		size++;
	}
	ft_rev_int_tab(num, size);
	ft_print_itoa(num, size);
	return ;
}

void	ft_rev_int_tab(int *num, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		temp = num[i];
		num[i] = num[size - i -1];
		num[size - i -1] = temp;
		i++;
	}
	return ;
}

void	ft_print_itoa(int *num, int size)
{
	char	cnum[10];
	int		i;

	i = 0;
	while (i < size)
	{
		cnum[i] = num[i] + '0';
		write(1, &cnum[i], 1);
		i++;
	}
	return ;
}
