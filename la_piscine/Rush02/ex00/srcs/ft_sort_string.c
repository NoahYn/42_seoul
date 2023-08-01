/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:00:02 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/11 18:16:19 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ':' && s[i] != 0 && !ft_space(s[i]))
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	s1_len;
	int	s2_len;

	s1_len = ft_len(s1);
	s2_len = ft_len(s2);
	if (s1_len != s2_len)
		return (s1_len - s2_len);
	else
	{
		i = 0;
		while (s1[i] != ':' && !ft_space(s1[i]))
		{
			if (s1[i] != s2[i])
				break ;
			i++;
		}
		return (s1[i] - s2[i]);
	}
}

void	ft_sort_string(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (tab[i] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
