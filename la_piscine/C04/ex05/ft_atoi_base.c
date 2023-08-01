/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:09:52 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/09 21:14:00 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_base_error(char *base)
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
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (1);
		if (tab[(int)base[i]] == 1)
			return (1);
		tab[(int)base[i]] = 1;
		i++;
	}
	return (0);
}

int	ft_skip(char *str, int *neg_cnt)
{	
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(*neg_cnt)++;
		i++;
	}
	return (i);
}

int	ft_is_base(char c, char *base, int base_len)
{
	int	j;

	j = 0;
	while (j < base_len)
	{
		if (c == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{	
	int			i;
	int			neg_cnt;
	int			base_len;
	long long	num;

	num = 0;
	neg_cnt = 0;
	base_len = ft_len(base);
	i = ft_skip(str, &neg_cnt);
	if (base_len < 2 || ft_base_error(base))
		return (0);
	while (ft_is_base(str[i], base, base_len) > -1)
	{
		num = num * base_len + ft_is_base(str[i], base, base_len);
		i++;
	}
	if (neg_cnt % 2 == 1)
		num = num * -1;
	return (num);
}
