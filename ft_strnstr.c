/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:27:12 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/02 20:54:10 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	int	i;
	int	len_needle;
	int	skip;

	len_needle = 0;
	while (needle[len_needle])
		len_needle++;
	if (len_needle == 0)
		return (haystack);
	i = 0;
	while (haystack[i] && len)
	{
		skip = ft_strncmp(haystack + i, needle, len_needle);
		if (skip == 0)
			return (haystack + i);
		i += skip;
		len--;
	}
	return (0);
}
