/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:53:46 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/15 01:27:13 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (0);
	result = (int *)malloc(sizeof(int) * (long)(max - min));
	if (result == 0)
		return (0);
	i = 0;
	while (min < max)
		result[i++] = min++;
	return (result);
}
