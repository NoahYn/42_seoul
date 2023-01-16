/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:27:12 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/16 19:29:56 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			len_needle;
	size_t			i;
	unsigned char	pattern[256];
	int				ri;

	len_needle = ft_strlen(needle);
	if (!len_needle)
		return ((char *)haystack);
	ft_memset(pattern, len_needle, 256);
	i = -1;
	while (++i < len_needle)
		pattern[(unsigned char)needle[i]] = len_needle - i - 1;
	i = 0;
	while (haystack[i] && i + len_needle <= len)
	{
		ri = len_needle - 1;
		while (haystack[i + ri] == needle[ri] && ri >= 0)
			--ri;
		if (ri == -1)
			return ((char *)haystack + i);
		i += pattern[(unsigned char)haystack[i + ri]] + ri - len_needle + 1;
	}
	return (0);
}
