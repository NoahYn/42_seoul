/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:02:41 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/13 11:06:01 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	i;
	long long	num;

	num = (long long)nb;
	i = 2;
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (num % i == 0)
		{
			num++;
			i = 1;
		}
		i++;
		if (i * i > num)
			return (num);
	}
}
