/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:48:20 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/11 20:03:55 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	join_len2(char **strs, int *i_2, int *j_2, int *str_len_2)
{
	int	i;
	int	j;
	int	str_len;

	i = *i_2;
	j = *j_2;
	str_len = *str_len_2;
	while (ft_num(strs[i][j]))
	{
		j++;
		str_len++;
	}
	while (ft_space(strs[i][j]))
		j++;
	if (strs[i][j++] == ':')
		str_len++;
	else
		return (0);
	*i_2 = i;
	*j_2 = j;
	*str_len_2 = str_len;
	return (1);
}

int	ft_join_len(char **strs, char *sep, int size)
{
	int	result;
	int	str_len;
	int	i;
	int	j;

	str_len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		if (!(join_len2(strs, &i, &j, &str_len)))
			return (-1);
		while (ft_space(strs[i][j]))
			j++;
		while (ft_printable(strs[i][j]))
		{
			j++;
			str_len++;
		}
		if (!(strs[i][j] == '\0'))
			return (-1);
		i++;
	}
	result = ft_strlen(sep) * (size - 1) + str_len;
	return (result);
}

char	*ft_join(int size, char **strs, char *sep, char *join)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (ft_num(strs[i][j]))
			join[k++] = strs[i][j++];
		while (ft_space(strs[i][j]))
			j++;
		if (strs[i][j] == ':')
			join[k++] = strs[i][j++];
		while (ft_space(strs[i][j]))
			j++;
		while (ft_printable(strs[i][j]))
			join[k++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			join[k++] = sep[j++];
	}
	join[k] = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;

	if (size == 0)
	{
		join = (char *)malloc(sizeof(char));
		join[0] = '\0';
		return (join);
	}
	if (ft_join_len(strs, sep, size) < 0)
		return (0);
	join = (char *)malloc(sizeof(char) * (ft_join_len(strs, sep, size) + 1));
	if (join == 0)
		return (0);
	return (ft_join(size, strs, sep, join));
}
