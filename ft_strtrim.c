/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:56 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/16 17:57:12 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_checkset(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
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
		return (0);
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
	while (start < end)
		strtrim[i++] = s1[start++];
	strtrim[i] = 0;
	return (strtrim);
}
