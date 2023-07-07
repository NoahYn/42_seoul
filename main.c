/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:43:18 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_pushswap *ps)
{
	int	num;
	int	i;

	if (ps->a.size <= 5)
		sort_small_a(ps);
	init_tri(ps);
	num = ps->a.size;
	i = -1;
	if (ps->tri.depth % 2 == 0)
		do_cmds(ps, "pb", ps->a.size);
	init_trichunk(ps, num, i);
	init_triorder(ps, num, i);
	if (ps->tri.depth % 2 == 1)
		init_triunit_b(ps);
	else
		init_triunit_a(ps);
	while (ps->tri.depth--)
	{
		if (ps->tri.depth % 2 == 1)
			merge_a2b(ps);
		else
			merge_b2a(ps);
	}
}

int	main(int argc, char *argv[])
{
	t_pushswap	ps;

	if (argc < 2)
		exit(1);
	init_ps(&ps);
	check_err(&ps, argv);
	if (cnt_inverse_order(&ps.a) == 0)
		exit_program(&ps, 0);
	sort_stack(&ps);
	print_cmd(&ps.cmd);
	exit_program(&ps, 0);
}
