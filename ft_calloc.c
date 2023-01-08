/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:19:08 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 11:31:08 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*mem;

	if (!count && !size)
		return (0);
	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (0);
	i = 0;
	while (i < count * size)
		mem[i++] = 0;
	return ((void *)mem);
}
