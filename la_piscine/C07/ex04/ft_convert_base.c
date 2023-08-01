/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:33:13 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/14 22:41:25 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len_err(char *base);
int	ft_atoi_base(char *nbr, char *base, int len);

int	ft_digit(long long n, int b_len)
{
	int	r_len;

	r_len = 0;
	if (n < 0)
	{
		n *= -1;
		r_len += 1;
	}
	if (n == 0)
		r_len += 1;
	while (n)
	{
		r_len++;
		n /= b_len;
	}
	return (r_len);
}

char	*ft_result(char *result, char *base, long long n, int bs_len[2])
{
	int	base_len;
	int	result_len;

	base_len = bs_len[0];
	result_len = bs_len[1];
	result_len -= 1;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n)
	{
		result[result_len] = base[n % base_len];
		n /= base_len;
		result_len--;
	}
	return (result);
}

char	*ft_itoa_base(int nbr, char *base, int base_len)
{
	char		*result;
	int			res_len;
	int			br_len[2];
	long long	n;

	n = nbr;
	res_len = ft_digit(n, base_len);
	result = (char *)malloc(sizeof(char) * (res_len + 1));
	if (result == 0)
		return (0);
	result[res_len] = '\0';
	if (n == 0)
		result[0] = base[0];
	else
	{
		br_len[0] = base_len;
		br_len[1] = res_len;
		result = ft_result(result, base, n, br_len);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	temp;
	int	len_to;
	int	len_from;

	if (base_to == 0 || base_from == 0)
		return (0);
	len_to = ft_len_err(base_to);
	len_from = ft_len_err(base_from);
	if (len_to < 2 || len_from < 2)
		return (0);
	temp = ft_atoi_base(nbr, base_from, len_from);
	return (ft_itoa_base(temp, base_to, len_to));
}
