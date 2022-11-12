/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:24:36 by subilee           #+#    #+#             */
/*   Updated: 2022/09/04 11:24:47 by subilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row(int row, int cur, int **board)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[row][i] == cur)
			return (0);
		i++;
	}
	return (1);
}

int	check_col(int col, int cur, int **board)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[i][col] == cur)
			return (0);
		i++;
	}
	return (1);
}
