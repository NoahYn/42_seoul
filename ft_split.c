/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:03:21 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 18:34:47 by sunyoon          ###   ########.fr       */
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
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				++i;
			++cnt;
		}
		else
			++i;
	}
	return (cnt);
}

static char	*ft_putstr(char const *s, int i, char c)
{
	char	*str;
	int		len;

	len = i;
	while (s[len] != c)
		++len;
	len -= i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = 0;
	while (len--)
		str[len] = s[i + len];
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		num_str;
	int		i;
	int		si;

	if (!s)
		return (0);
	num_str = ft_cntstr(s, c);
	split = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (split == 0)
		return (0);
	split[num_str] = 0;
	i = 0;
	si = 0;
	while (split[si])
	{
		while (s[i] == c)
			++i;
		if (s[i])
			split[si++] = ft_putstr(s, i, c);
		while (s[i] != c)
			++i;
	}
	return (split);
}
