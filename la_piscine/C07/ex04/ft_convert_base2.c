/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:44:21 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/14 22:25:19 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len_err(char *base)
{
	int				i;
	unsigned char	tab[256];

	i = 0;
	while (i < 256)
		tab[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13) || tab[(int)base[i]] == 1)
			return (0);
		tab[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

int	ft_is_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base, int len)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ') && nbr[i])
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nbr[i] && ft_is_base(base, nbr[i]) > -1)
		result = result * len + ft_is_base(base, nbr[i++]);
	result *= neg;
	return (result);
}
