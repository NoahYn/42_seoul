/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:03:00 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:43:48 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_pushswap	ps;
	char		cmd[4];
	int			byte;

	if (argc < 2)
		return (0);
	init_ps(&ps);
	check_err(&ps, argv);
	byte = 1;
	while (byte)
	{
		byte = read(0, cmd, 4);
		cmd[byte] = 0;
		do_cmds(&ps, cmd, 1);
	}
	if (ps.b.size == 0 && cnt_inverse_order(&ps.a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_program(&ps, 0);
}
