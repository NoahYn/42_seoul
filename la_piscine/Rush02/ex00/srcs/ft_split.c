/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:43:33 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/10 19:48:46 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_check_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

int	ft_str_len(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		while (str[i] != 0 && ft_check_set(str[i], charset) == 1)
			i++;
		if (str[i] != 0)
			cnt++;
		while (str[i] != 0 && ft_check_set(str[i], charset) == -1)
			i++;
	}
	return (cnt);
}

int	ft_word_len(char *str, int i, char *charset)
{
	int	origin_i;

	origin_i = i;
	while (str[i] != 0 && ft_check_set(str[i], charset) == -1)
		i++;
	return (i - origin_i);
}

char	*ft_word_put(char *str, int str_i, char *charset)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = ft_word_len(str, str_i, charset);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == 0)
		return (0);
	word[word_len] = 0;
	i = 0;
	while (i < word_len)
	{
		word[i] = str[str_i];
		i++;
		str_i++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		split_len;
	int		i;
	int		j;

	split_len = ft_str_len(str, charset);
	split = (char **)malloc(sizeof(char *) * (split_len + 1));
	if (split == 0)
		return (0);
	split[split_len] = 0;
	i = 0;
	j = 0;
	while (j < split_len)
	{
		while (str[i] != 0 && ft_check_set(str[i], charset) == 1)
			i++;
		if (str[i] != 0)
		{
			split[j] = ft_word_put(str, i, charset);
			j++;
		}
		while (str[i] != 0 && ft_check_set(str[i], charset) == -1)
			i++;
	}
	return (split);
}
