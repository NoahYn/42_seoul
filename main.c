/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 00:50:23 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_pushswap *ps)
{
	int	num;
	int	i;

	if (ps->a.size <= 5)
	{
		sort_small_a(ps);
		return ;
	}
	ps->tri.depth = 1;
	while (ft_pow(3, ps->tri.depth -1) * 18 < ps->a.size)
		ps->tri.depth++;
	ps->tri.num = ft_pow(3, ps->tri.depth);
	num = ps->a.size;
	ps->tri.chunk = (int *)malloc(sizeof(int) * ps->tri.num);
	ps->tri.order = (int *)malloc(sizeof(int) * ps->tri.num);
	ps->tri.push_cnt = 0;
	i = -1;
	if (ps->tri.depth % 2 == 0)
		do_cmds(ps, "pb", ps->a.size);
	while (num > 0)
	{
		++i;
		ps->tri.chunk[i] = num / (ps->tri.num - i);
		num -= num / (ps->tri.num - i);
		if (i >= ps->tri.num / 3 * 2)
			ps->tri.push_cnt += ps->tri.chunk[i];
		if (ps->tri.chunk[i] > 2)
		{
			if (ps->tri.depth % 2 == 1)
				do_cmds(ps, "pb", ps->tri.chunk[i] / 3);
			else
				do_cmds(ps, "pa", ps->tri.chunk[i] / 3);
		}
	}
	ps->tri.order[0] = INC;
	num = -1;
	while (ft_pow(3, ++num) < ps->tri.num)
	{
		i = -1;
		while (++i < ft_pow(3, num))
		{
			ps->tri.order[ft_pow(3, num) * 2 - i -1] = ps->tri.order[i] * -1;
			ps->tri.order[ft_pow(3, num) * 3 - i -1] = ps->tri.order[i] * -1;
		}
	}
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
	init(&ps);
	check_err(&ps, argv);
	if (cnt_inverse_order(&ps.a) == 0)
		exit_program(&ps, 0);
	sort_stack(&ps);
	print_cmd(&ps.cmd);
	exit_program(&ps, 0);
}
