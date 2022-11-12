/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:24:31 by youngkpa          #+#    #+#             */
/*   Updated: 2022/09/11 23:21:22 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_three2(char t_num[4], int unit, char *dic)
{
	if (t_num[1] != '0')
	{
		if (t_num[1] == '1')
		{
			ft_print_two(&t_num[1], unit, dic);
			if (unit != 1)
				ft_print_one('1', unit, unit, dic);
			return ;
		}
		else if (t_num[2] == '0')
			ft_print_one(t_num[1], 2, unit, dic);
		else
			ft_print_one(t_num[1], 2, unit + 1, dic);
	}
	if (t_num[2] != '0')
		ft_print_one(t_num[2], 1, unit, dic);
	if (unit != 1)
		ft_print_one('1', unit, unit, dic);
}

void	ft_print_three(char t_num[4], int unit, char *dic)
{
	if (t_num[0] == '0' && t_num[1] == '0' && t_num[2] == '0')
		return ;
	if (t_num[0] != '0')
	{
		ft_print_one(t_num[0], 1, unit + 1, dic);
		if (t_num[1] == '0' && t_num[2] == '0')
			ft_print_one('1', 3, unit, dic);
		else
			ft_print_one('1', 3, unit + 1, dic);
	}
	ft_print_three2(t_num, unit, dic);
}

void	init_t_num(char t_num[4], char *num, int digit)
{
	t_num[0] = '0';
	t_num[1] = '0';
	t_num[2] = '0';
	t_num[3] = '\0';
	ft_strncpy(&t_num[3 - digit], num, digit);
}

void	ft_print_all2(char *num, char *dic, int digit)
{
	char		t_num[4];

	init_t_num(t_num, num, digit % 3);
	if (digit % 3)
	{
		ft_print_three(t_num, (digit -1) / 3 * 3 + 1, dic);
		num += (digit % 3);
		digit -= (digit % 3);
	}
	while (*num)
	{
		ft_print_three(ft_strncpy(t_num, num, 3), digit - 3 + 1, dic);
		num += 3;
		digit -= 3;
	}
	write(1, "\n", 1);
	return ;
}

int	ft_print_all(char *num, char *dic)
{
	int			digit;

	digit = ft_strlen(num);
	if (digit > 39)
		return (0);
	if (*num == '0' && digit == 1)
	{
		ft_print_one(num[0], 1, digit, dic);
		write(1, "\n", 1);
		return (1);
	}
	ft_print_all2(num, dic, digit);
	return (1);
}
