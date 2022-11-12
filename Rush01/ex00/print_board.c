/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:23:23 by subilee           #+#    #+#             */
/*   Updated: 2022/09/04 16:26:51 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int **board)
{
	int		row;
	int		col;
	char	box;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			box = board[row][col] + '0';
			write(1, &box, 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
