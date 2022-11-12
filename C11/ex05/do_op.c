/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:58:54 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/15 20:45:13 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}

void	ft_cal(int num1, int num2, char op)
{
	if (op == '+')
	{
		ft_putnbr(num1 + num2);
		write(1, "\n", 1);
	}
	else if (op == '-')
	{
		ft_putnbr(num1 - num2);
		write(1, "\n", 1);
	}
	else if (op == '*')
	{
		ft_putnbr(num1 * num2);
		write(1, "\n", 1);
	}
	else if (op == '/')
	{
		ft_putnbr(num1 / num2);
		write(1, "\n", 1);
	}
	else
	{
		ft_putnbr(num1 % num2);
		write(1, "\n", 1);
	}
}

void	ft_do_op(char **argv)
{
	int		num1;
	int		num2;
	char	op;

	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	op = argv[2][0];
	if (op == '/' && num2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	if (op == '%' && num2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_cal(num1, num2, op);
}
