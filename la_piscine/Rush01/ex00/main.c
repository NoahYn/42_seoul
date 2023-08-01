/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:18:14 by subilee           #+#    #+#             */
/*   Updated: 2022/09/04 19:18:28 by subilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_input(char *str, int *nums);
int		check_solvable(int *nums);
void	solve(int row, int col, int **board, int *nums);

int	**alloc_board(void)
{
	int	**board;
	int	i;

	board = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
		board[i++] = (int *)malloc(sizeof(int) * 4);
	return (board);
}

void	free_mem(int **board, int *nums)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(board[i]);
		board[i] = 0;
		i++;
	}
	free(board);
	board = 0;
	free(nums);
	nums = 0;
}

void	init_board(int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			board[i][j++] = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	**board;
	int	*nums;

	board = alloc_board();
	nums = (int *)malloc(sizeof(int) * 16);
	init_board(board);
	if (ac == 2 && board != 0 && nums != 0)
	{
		if (check_input(av[1], nums) && check_solvable(nums))
			solve(0, 0, board, nums);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	free_mem(board, nums);
}
