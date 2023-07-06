/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:27:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 00:02:09 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(int min_idx[2], t_stack *stk)
{
	int		min[2];
	int		idx;
	t_node	*curr;

	curr = stk->top;
	min[0] = INTMAX;
	min[1] = INTMAX;
	min_idx[0] = -1;
	min_idx[1] = -1;
	idx = 0;
	while (curr)
	{
		idx++;
		if (min[0] > curr->item)
		{
			min[1] = min[0];
			min_idx[1] = min_idx[0];
			min[0] = curr->item;
			min_idx[0] = idx;
		}
		else if (min[1] > curr->item)
		{
			min[1] = curr->item;
			min_idx[1] = idx;
		}
		curr = curr->prev;
	}
}

void	sort_three_a(t_pushswap *ps)
{
	if (AT < AS && AT < AB)
	{
		if (AS < AB)
			return ;
		sa(ps);
	}
	if (AT > AS && AT > AB)
	{
		if (AS < AB)
			ra(ps);
		else
			do_cmds(ps, "sa rra", 1);
	}
	else
	{
		if (AS < AB)
			sa(ps);
		else
			rra(ps);
	}
}

void	pb_min(t_pushswap *ps, int num)
{
	int	min_idx[2];

	find_min(min_idx, &ps->a);
	if (num == 2)
	{
		if (min_idx[0] == 1 || min_idx[1] == 1)
			;
		else if (min_idx[0] == 2 || min_idx[1] == 2)
			ra(ps);
		else if (min_idx[0] == 5 || min_idx[1] == 5)
			rra(ps);
		else
			do_cmds(ps, "ra", 2);
		pb(ps);
	}
	find_min(min_idx, &ps->a);
	if (min_idx[0] == 4)
		rra(ps);
	else
		while (min_idx[0]-- > 1)
			ra(ps);
	pb(ps);
}

void	sort_small_a(t_pushswap *ps)
{
	if (ps->a.size == 2)
		sa(ps);
	else if (ps->a.size == 3)
		sort_three_a(ps);
	else
	{
		pb_min(ps, ps->a.size - 3);
		sort_three_a(ps);
		if (ps->b.size == 2 && ps->b.top->item < ps->b.top->prev->item)
			sb(ps);
		do_cmds(ps, "pa", ps->b.size);
	}
}
