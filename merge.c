/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:12:40 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 01:30:08 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_aab(t_pushswap *ps, int seq)
{
	if (seq == 1)
		pb(ps);
	else if (seq == 2)
		do_cmds(ps, "rra pb", 1);
	else if (seq == 3)
		rrb(ps);
	else if (seq == 4)
		do_cmds(ps, "sa pb", 1);
	else if (seq == 5)
		do_cmds(ps, "rra rra pb ra", 1);
	else if (seq == 6)
		do_cmds(ps, "rrb rrb sb rb", 1);
}

void	merge_bba(t_pushswap *ps, int seq)
{
	if (seq == 1)
		pa(ps);
	else if (seq == 2)
		do_cmds(ps, "rrb pa", 1);
	else if (seq == 3)
		rra(ps);
	else if (seq == 4)
		do_cmds(ps, "sb pa", 1);
	else if (seq == 5)
		do_cmds(ps, "rrb rrb pa rb", 1);
	else if (seq == 6)
		do_cmds(ps, "rra rra sa ra", 1);
}

void	merge_a2b(t_pushswap *ps)
{
	int		i;
	int		arr[3];
	int		size[3];

	do_cmds(ps, "pb", ps->tri.push_cnt);
	ps->tri.push_cnt = 0;
	ps->tri.num /= 3;
	i = -1;
	while (++i < ps->tri.num)
	{
		size[0] = ps->tri.chunk[ps->tri.num * 2 - i -1];
		size[1] = ps->tri.chunk[i];
		size[2] = ps->tri.chunk[ps->tri.num * 3 - i -1];
		ps->tri.chunk[i] = size[0] + size[1] + size[2];
		if (i >= ps->tri.num / 3 * 2)
			ps->tri.push_cnt += ps->tri.chunk[i];
		while (size[0] || size[1] || size[2])
			
		{
			if (ps->a.size > 0)
			{
				arr[0] = AT;
				arr[1] = AB;
			}
			if (ps->b.size > 0)
				arr[2] = BB;
			if (ps->tri.order[i] == DEC)
				merge_aab(ps, min_element(3, arr, size));
			else
				merge_aab(ps, max_element(3, arr, size));
		}
	}
}

void	merge_b2a(t_pushswap *ps)
{
	int		i;
	int		arr[3];
	int		size[3];

	do_cmds(ps, "pa", ps->tri.push_cnt);
	ps->tri.push_cnt = 0;
	ps->tri.num /= 3;
	i = -1;
	while (++i < ps->tri.num)
	{
		size[1] = ps->tri.chunk[i];
		size[0] = ps->tri.chunk[ps->tri.num * 2 - i -1];
		size[2] = ps->tri.chunk[ps->tri.num * 3 - i -1];
		ps->tri.chunk[i] = size[0] + size[1] + size[2];
		if (i >= ps->tri.num / 3 * 2)
			ps->tri.push_cnt += ps->tri.chunk[i];
		while (size[0] || size[1] || size[2])
		{
			if (ps->b.size > 0)
			{
				arr[0] = BT;
				arr[1] = BB;
			}
			if (ps->a.size > 0)
				arr[2] = AB;
			if (ps->tri.order[i] == DEC)
				merge_bba(ps, min_element(3, arr, size));
			else
				merge_bba(ps, max_element(3, arr, size));
		}
	}
}
