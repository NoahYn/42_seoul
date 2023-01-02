/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:19:08 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/02 21:34:53 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*calloc(unsigned int count, unsigned int size)
{
	int		i;
	char	*mem;

	if (!count && !size)
		return (0);
	mem = (char *)malloc(count * size);
	if (mem == 0)
		return (0);
	i = 0;
	while (i < count * size)
		mem[i++] = 0;
	return ((void *)mem);
}
