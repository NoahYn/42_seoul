/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:56:31 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/15 23:59:48 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = 0;
	up = 0;
	down = 0;
	if (length < 2)
		return (1);
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			down++;
		if (f(tab[i], tab[i + 1]) < 0)
			up++;
		i++;
	}
	if (up == 0 || down == 0)
		return (1);
	return (0);
}
