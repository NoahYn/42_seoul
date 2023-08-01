/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:05:33 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/14 21:45:33 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*result;
	int	size;
	int	i;

	size = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	result = (int *)malloc(sizeof(int) * (size));
	if (result == 0)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (min < max)
		result[i++] = min++;
	*range = result;
	return (size);
}
