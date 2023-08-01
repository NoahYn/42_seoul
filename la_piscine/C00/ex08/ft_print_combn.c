/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:47:02 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/06 20:46:14 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recur(char *arr, int curr, int n);

void	ft_print_combn(int n)
{
	int		i;
	char	arr[10];
	char	last;

	i = 0;
	while (i < n)
	{
		arr[i] = '0' + i;
		i++;
	}
	last = 10 - n + '0';
	while (arr[0] < last)
	{
		write(1, arr, n);
		write(1, ", ", 2);
		arr[n - 1]++;
		if (arr[n - 1] == '9')
			ft_recur(arr, 1, n);
	}
	while (last <= '9')
	{
		write(1, &last, 1);
		last++;
	}
	return ;
}

void	ft_recur(char *arr, int curr, int n)
{
	int		i;
	char	max;

	max = 10 - curr + '0';
	if (arr[n - curr] != max)
		arr[n - curr]++;
	i = 0;
	while (i < curr)
	{
		arr[n - curr + i + 1] = arr[n - curr + i] + 1;
		i++;
	}
	if (curr > 1 && arr[n - curr + 1] < max + 1)
		return ;
	else if (curr < n && arr[n - curr] == max)
	{
		write(1, arr, n);
		write(1, ", ", 2);
		ft_recur(arr, ++curr, n);
	}
}
/*
int	main(int argc, char **argv)
{
	argv = 0;
	ft_print_combn(argc);
	return (0);
}*/
