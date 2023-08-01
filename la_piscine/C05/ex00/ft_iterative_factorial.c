/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:12:46 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/10 12:21:29 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fac;

	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	fac = nb;
	while (nb > 1)
	{
		nb--;
		fac *= nb;
	}
	return (fac);
}
