/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:03:21 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/17 15:14:58 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_cntstr(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		if (s[i])
			++cnt;
		while (s[i] && s[i] != c)
			++i;
	}
	return (cnt);
}

static int	ft_putstr(char const *s, char c, char **result, int si)
{
	char	*str;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		++len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		while (--si >= 0)
			free(result[si]);
		free(result);
		return (0);
	}
	str[len] = 0;
	while (len--)
		str[len] = s[len];
	result[si] = str;
	return (1);
}

static char	**get_result(size_t n)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (n + 1));
	if (!result)
		return (0);
	result[n] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	num_str;
	size_t	i;
	size_t	si;

	if (!s)
		return (0);
	num_str = ft_cntstr(s, c);
	result = get_result(num_str);
	if (!result)
		return (0);
	i = 0;
	si = 0;
	while (si < num_str)
	{
		while (s[i] && s[i] == c)
			++i;
		if (!ft_putstr(s + i, c, result, si))
			return (0);
		si++;
		while (s[i] && s[i] != c)
			++i;
	}
	return (result);
}
