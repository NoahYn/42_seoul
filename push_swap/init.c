/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 08:33:40 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:44:43 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_pushswap *ps)
{
	t_node2	*cmd_head;

	ps->a.size = 0;
	ps->a.top = NULL;
	ps->a.bottom = NULL;
	ps->b.size = 0;
	ps->b.top = NULL;
	ps->b.bottom = NULL;
	cmd_head = (t_node2 *)malloc(sizeof(t_node2));
	if (!cmd_head)
		exit_program(ps, 0);
	cmd_head->next = NULL;
	cmd_head->prev = NULL;
	ft_strlcpy(cmd_head->cmd, "", 1);
	ps->cmd.first = cmd_head;
	ps->cmd.last = cmd_head;
	ps->split = 0;
	ps->tri.chunk = 0;
}

void	init_triorder(t_pushswap *ps, int num, int i)
{
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
}

void	init_trichunk(t_pushswap *ps, int num, int i)
{
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
}

void	init_tri(t_pushswap *ps)
{
	ps->tri.depth = 1;
	while (ft_pow(3, ps->tri.depth -1) * 18 < ps->a.size)
		ps->tri.depth++;
	ps->tri.num = ft_pow(3, ps->tri.depth);
	ps->tri.chunk = (int *)malloc(sizeof(int) * ps->tri.num);
	ps->tri.order = (int *)malloc(sizeof(int) * ps->tri.num);
	if (!ps->tri.chunk || !ps->tri.order)
		exit_program(ps, 0);
	ps->tri.push_cnt = 0;
}
