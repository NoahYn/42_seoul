/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:12:40 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:49:38 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_init(t_pushswap *ps, int size[3])
{
	size[0] = ps->tri.chunk[ps->tri.num * 2 - ps->i -1];
	size[1] = ps->tri.chunk[ps->i];
	size[2] = ps->tri.chunk[ps->tri.num * 3 - ps->i -1];
	ps->tri.chunk[ps->i] = size[0] + size[1] + size[2];
	if (ps->i >= ps->tri.num / 3 * 2)
		ps->tri.push_cnt += ps->tri.chunk[ps->i];
}

void	merge_a2b(t_pushswap *ps)
{
	int		arr[3];
	int		size[3];

	do_cmds(ps, "pb", ps->tri.push_cnt);
	ps->tri.push_cnt = 0;
	ps->tri.num /= 3;
	ps->i = -1;
	while (++ps->i < ps->tri.num)
	{
		merge_init(ps, size);
		while (size[0] || size[1] || size[2])
		{
			if (ps->a.size > 0)
			{
				arr[0] = ps->a.top->item;
				arr[1] = ps->a.bottom->item;
			}
			if (ps->b.size > 0)
				arr[2] = ps->b.bottom->item;
			if (ps->tri.order[ps->i] == DEC)
				merge_aab(ps, min_element(3, arr, size));
			else
				merge_aab(ps, max_element(3, arr, size));
		}
	}
}

void	merge_b2a(t_pushswap *ps)
{
	int		arr[3];
	int		size[3];

	do_cmds(ps, "pa", ps->tri.push_cnt);
	ps->tri.push_cnt = 0;
	ps->tri.num /= 3;
	ps->i = -1;
	while (++ps->i < ps->tri.num)
	{
		merge_init(ps, size);
		while (size[0] || size[1] || size[2])
		{
			if (ps->b.size > 0)
			{
				arr[0] = ps->b.top->item;
				arr[1] = ps->b.bottom->item;
			}
			if (ps->a.size > 0)
				arr[2] = ps->a.bottom->item;
			if (ps->tri.order[ps->i] == DEC)
				merge_bba(ps, min_element(3, arr, size));
			else
				merge_bba(ps, max_element(3, arr, size));
		}
	}
}
