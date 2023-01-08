/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:56 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 14:32:57 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_checkset(const char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return ((char *)s1);
	start = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	while (start < end && ft_checkset(s1[end - 1], set))
		end--;
	strtrim = (char *)malloc(end - start + 1);
	if (!strtrim)
		return (0);
	i = 0;
	while (start < end && s1[start])
		strtrim[i++] = s1[start++];
	strtrim[end - start] = 0;
	return (strtrim);
}
