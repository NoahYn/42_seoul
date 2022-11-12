/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:09:28 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/09 21:03:46 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len2(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_base_error2(char *base)
{
	int				i;
	unsigned char	tab[256];

	i = 0;
	while (i < 256)
		tab[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (tab[(int)base[i]] == 1)
			return (1);
		tab[(int)base[i]] = 1;
		i++;
	}
	return (0);
}

void	ft_print_base(long long nbr, char *base, int base_len)
{
	if (nbr == 0)
		return ;
	ft_print_base(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long long	n;

	base_len = ft_len2(base);
	n = (long long)nbr;
	if (base_len < 2 || ft_base_error2(base))
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(1, &base[nbr % base_len], 1);
	else
		ft_print_base(n, base, base_len);
	return ;
}
