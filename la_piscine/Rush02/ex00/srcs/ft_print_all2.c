/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:37:27 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/11 23:36:08 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*num_and_zeros(char c, int digit)
{
	char	*num;
	int		idx;

	num = (char *)malloc(sizeof(char) * (digit + 1));
	*num = c;
	idx = 1;
	while (idx < digit)
		num[idx++] = '0';
	num[digit] = '\0';
	return (num);
}

void	ft_print_one(char num, int zeros, int unit, char *dic)
{
	char	*n;

	n = num_and_zeros(num, zeros);
	dic = ft_strstr(dic, n);
	dic = ft_strstr(dic, ":");
	dic++;
	while (*dic != '\n' && *dic != '\0')
	{
		write(1, dic, 1);
		dic++;
	}
	free(n);
	if (unit != 1)
		write(1, " ", 1);
}

void	ft_print_two(char *n, int unit, char *dic)
{
	dic = ft_strstr(dic, n);
	dic = ft_strstr(dic, ":");
	dic++;
	while (*dic != '\n' && *dic != '\0')
	{
		write(1, dic, 1);
		dic++;
	}
	if (unit != 1)
		write(1, " ", 1);
}
