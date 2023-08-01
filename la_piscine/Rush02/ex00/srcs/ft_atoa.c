/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:18:31 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/13 12:14:56 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	atoa_space(char *str, int *i_f)
{
	int	i;
	int	flag;

	i = i_f[0];
	flag = i_f[1];
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	i_f[0] = i;
	i_f[1] = flag;
}

char	*ft_atoa(char *str)
{
	int		i_f[2];
	int		sta_end[2];
	char	*result;

	i_f[0] = 0;
	i_f[1] = 1;
	atoa_space(str, i_f);
	if (!(str[i_f[0]] >= '0' && str[i_f[0]] <= '9'))
	{
		result = ft_strdup("0", 0, 1);
		return (result);
	}
	while (str[i_f[0]] != 0 && str[i_f[0]] == '0'
		&& (str[i_f[0] + 1] >= '0' && str[i_f[0] + 1] <= '9'))
		i_f[0]++;
	sta_end[0] = i_f[0];
	while (str[i_f[0]] && str[i_f[0]] >= '0' && str[i_f[0]] <= '9')
		i_f[0]++;
	sta_end[1] = i_f[0];
	result = ft_strdup(str, sta_end[0], sta_end[1]);
	if (i_f[1] == -1 && result[0] == '0')
		return (result);
	else if (i_f[1] == -1)
		return (0);
	return (result);
}
