/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_rc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:25:08 by subilee           #+#    #+#             */
/*   Updated: 2022/09/04 11:25:35 by subilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_valid_row(int **board, int *nums, int row);
void	valid_row(int *cnt, int **board, int row);
int		check_valid_col(int **board, int *nums, int col);
void	valid_col(int *cnt, int **board, int col);

int	check_valid_row(int **board, int *nums, int row)
{
	int	cnt[2];

	cnt[0] = 0;
	cnt[1] = 0;
	valid_row(cnt, board, row);
	if (cnt[0] == nums[row + 8] && cnt[1] == nums[row + 12])
		return (1);
	else
		return (0);
}

void	valid_row(int *cnt, int **board, int row)
{
	int	index[2];
	int	max[2];

	index[0] = 0;
	index[1] = 3;
	max[0] = board[row][0];
	max[1] = board[row][3];
	while (index[0] < 4)
	{
		if (max[0] <= board[row][index[0]])
		{
			cnt[0]++;
			max[0] = board[row][index[0]];
		}
		index[0]++;
	}
	while (index[1] >= 0)
	{
		if (max[1] <= board[row][index[1]])
		{
			cnt[1]++;
			max[1] = board[row][index[1]];
		}
		index[1]--;
	}
}

int	check_valid_col(int **board, int *nums, int col)
{
	int	cnt[2];

	cnt[0] = 0;
	cnt[1] = 0;
	valid_col(cnt, board, col);
	if (cnt[0] == nums[col] && cnt[1] == nums[col + 4])
		return (1);
	else
		return (0);
}

void	valid_col(int *cnt, int **board, int col)
{
	int	index[2];
	int	max[2];

	index[0] = 0;
	index[1] = 3;
	max[0] = board[0][col];
	max[1] = board[3][col];
	while (index[0] < 4)
	{
		if (max[0] <= board[index[0]][col])
		{
			cnt[0]++;
			max[0] = board[index[0]][col];
		}
		index[0]++;
	}
	while (index[1] >= 0)
	{
		if (max[1] <= board[index[1]][col])
		{
			cnt[1]++;
			max[1] = board[index[1]][col];
		}
		index[1]--;
	}
}
