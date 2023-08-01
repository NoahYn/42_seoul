/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:03:21 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/15 02:26:33 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcnt(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i])
			cnt++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	return (cnt);
}

int	ft_word_len(char *str, int i, char *charset)
{
	int	temp;

	temp = i;
	while (str[i] != 0 && !ft_is_charset(str[i], charset))
		i++;
	return (i - temp);
}

char	*ft_word_put(char *str, int idx, char *charset)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = ft_word_len(str, idx, charset);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == 0)
		return (0);
	word[word_len] = 0;
	i = 0;
	while (i < word_len)
	{
		word[i] = str[idx];
		i++;
		idx++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;
	int		w;

	words = ft_strcnt(str, charset);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == 0)
		return (0);
	split[words] = 0;
	i = 0;
	w = 0;
	while (w < words || split[words])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i])
			split[w++] = ft_word_put(str, i, charset);
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	return (split);
}
