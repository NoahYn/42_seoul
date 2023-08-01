/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:19:55 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/11 19:39:29 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strdup(char *src, int start, int end)
{
	char	*dup;
	int		src_len;
	int		i;

	src_len = end - start;
	dup = (char *)malloc(sizeof(char) * (src_len + 1));
	if (dup == 0)
		return (0);
	dup[src_len] = '\0';
	i = 0;
	while (start < end)
	{
		dup[i] = src[start];
		i++;
		start++;
	}
	return (dup);
}
