/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:22:14 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/10 12:26:21 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{	
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power % 2 == 0)
	{
		nb = nb * nb;
		power = power / 2;
	}
	res = 1;
	while (power--)
		res = res * nb;
	return (res);
}
