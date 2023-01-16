/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:03:21 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/16 18:58:50 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_cntstr(char const *s, char c)
{
	int	i;
	int	cnt;

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

static char	*ft_putstr(char const *s, char c)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		++len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = 0;
	while (len--)
		str[len] = s[len];
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_str;
	int		i;
	int		si;

	if (!s)
		return (0);
	num_str = ft_cntstr(s, c);
	result = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (result == 0)
		return (0);
	i = 0;
	si = 0;
	while (si < num_str)
	{
		while (s[i] && s[i] == c)
			++i;
		result[si++] = ft_putstr(s + i, c);
		while (s[i] && s[i] != c)
			++i;
	}
	result[si] = 0;
	return (result);
}
