/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:46:13 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/01 21:41:50 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	comb[1] = '0';
	comb[2] = '0';
	while (comb[0] < '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] < '9')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] < '9' + 1)
			{
				write(1, &comb[0], 1);
				write(1, &comb[1], 1);
				write(1, &comb[2], 1);
				comb[2]++;
				write(1, ", ", 2);
			}
			comb[1]++;
		}
		comb[0]++;
	}
	write(1, "789", 3);
	return ;
}
