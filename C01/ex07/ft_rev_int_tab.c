/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:05:33 by sunyoon           #+#    #+#             */
/*   Updated: 2022/08/30 14:23:36 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	if (size <= 0)
		return ;
	temp = 0;
	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i -1];
		tab[size -1 - i] = temp;
		i++;
	}
	return ;
}
