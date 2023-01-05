/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:27:12 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/05 16:25:48 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

static int	my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (s1[i] != s2[i])
			return (i + 1);
	return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	int		skip;

	len_needle = 0;
	while (needle[len_needle])
		len_needle++;
	if (len_needle == 0)
		return ((char *)haystack);
	while (*haystack && len_needle < len--)
	{
		skip = my_strncmp(haystack, needle, len_needle);
		if (skip == -1)
			return ((char *)haystack);
		haystack += skip;
	}
	return (0);
}
