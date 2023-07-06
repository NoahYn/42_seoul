/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:03:00 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 22:12:22 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_cmd	c;
	char	cmd[4];
	int		byte;

	if (argc < 2)
		return (0);
	init(&c, &a, &b);
	check_err(&c, &a, &b, argv);
	byte = 1;
	while (byte)
	{
		byte = read(0, cmd, 4);
		cmd[byte] = 0;
		do_cmds(cmd, &c, &a, &b);
	}
	if (b.size == 0 && cnt_inverse_order(&a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_program(&c, &a, &b, 0);
}
