/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:25:52 by subilee           #+#    #+#             */
/*   Updated: 2022/09/04 16:55:06 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_board(int **board);
int		check_valid_col(int **board, int *nums, int row);
int		check_valid_row(int **board, int *nums, int row);
int		check_row(int row, int cur, int **board);
int		check_col(int col, int cur, int **board);
void	recur(int row, int col, int **board, int *nums);

void	solve(int row, int col, int **board, int *nums)
{
	int	height;

	height = 1;
	while (height <= 4)
	{
		if (check_row(row, height, board) && check_col(col, height, board))
		{
			board[row][col] = height;
			if (row == 3 && col == 3)
			{
				print_board(board);
				return ;
			}
			recur(row, col, board, nums);
			board[row][col] = 0;
		}
		height++;
	}
}

void	recur(int row, int col, int **board, int *nums)
{
	if (col == 3 && row < 3)
	{
		if (check_valid_row(board, nums, row))
			solve(row + 1, 0, board, nums);
	}
	else if (row == 3)
	{
		if (check_valid_col(board, nums, col))
			solve(row, col + 1, board, nums);
	}
	else
		solve(row, col + 1, board, nums);
}
