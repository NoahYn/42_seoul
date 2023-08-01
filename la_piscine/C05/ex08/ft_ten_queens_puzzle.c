/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:27:59 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/10 15:57:52 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_board(int *board);

int	ft_check(int *board, int y, int sum_sub[2][19])
{
	int	idx;
	int	x;

	idx = 0;
	x = board[y];
	if (sum_sub[0][x + y] == 1 || sum_sub[1][x - y + 9] == 1)
		return (0);
	while (idx < y)
	{	
		if (board[y] == board[idx])
			return (0);
		idx++;
	}
	sum_sub[0][x + y] = 1;
	sum_sub[1][x - y + 9] = 1;
	return (1);
}

void	ft_put_queen(int *board, int y, int sum_sub[2][19], int *cnt)
{
	int	x;

	x = -1;
	while (++x < 10)
	{
		board[y] = x;
		if (!ft_check(board, y, sum_sub))
		{
			board[y] = 0;
			continue ;
		}
		if (y == 9)
		{
			(*cnt)++;
			ft_print_board(board);
			sum_sub[0][x + y] = 0;
			sum_sub[1][x - y + 9] = 0;
			return ;
		}
		ft_put_queen(board, y + 1, sum_sub, cnt);
		sum_sub[0][x + y] = 0;
		sum_sub[1][x - y + 9] = 0;
	}
}

int	ft_ten_queens_puzzle(void)
{	
	int	i;
	int	xy_sum_sub[2][19];
	int	board[10];
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 19)
	{
		if (i < 10)
			board[i] = 0;
		xy_sum_sub[0][i] = 0;
		xy_sum_sub[1][i] = 0;
		i++;
	}
	ft_put_queen(board, 0, xy_sum_sub, &cnt);
	return (cnt);
}

void	ft_print_board(int *board)
{
	int		y;
	char	cboard[10];

	y = 0;
	while (y < 10)
	{
		cboard[y] = board[y] + '0';
		write(1, &cboard[y++], 1);
	}
	write(1, "\n", 1);
	return ;
}
