/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:27:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 17:29:11 by sunyoon          ###   ########.fr       */
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

void	sort_three_a(t_cmd *cmd, t_stack *a, t_stack *b)
{
	if (AT < AS && AT < AB)
	{
		if (AS < AB)
			return ;
		sa(cmd, a, b);
	}
	if (AT > AS && AT > AB)
	{
		if (AS < AB)
			ra(cmd, a, b);
		else
			do_cmds("sa rra", cmd, a, b);
	}
	else
	{
		if (AS < AB)
			sa(cmd, a, b);
		else
			rra(cmd, a, b);
	}
}

void	pb_min(t_cmd *cmd, t_stack *a, t_stack *b, int num)
{
	int	min_idx[2];

	find_min(min_idx, a);
	if (num == 2)
	{
		if (min_idx[0] == 1 || min_idx[1] == 1)
			;
		else if (min_idx[0] == 2 || min_idx[1] == 2)
			ra(cmd, a, b);
		else if (min_idx[0] == 5 || min_idx[1] == 5)
			rra(cmd, a, b);
		else
			cmd_multiply("ra", 2, cmd, a, b);
		pb(cmd, a, b);
	}
	find_min(min_idx, a);
	if (min_idx[0] == 4)
		rra(cmd, a, b);
	else
		while (min_idx[0]-- > 1)
			ra(cmd, a, b);
	pb(cmd, a, b);
}

void	sort_small_a(t_cmd *cmd, t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(cmd, a, b);
	else if (a->size == 3)
		sort_three_a(cmd, a, b);
	else
	{
		pb_min(cmd, a, b, a->size - 3);
		sort_three_a(cmd, a, b);
		if (b->size == 2 && b->top->item < b->top->prev->item)
			sb(cmd, a, b);
		cmd_multiply("pa", b->size, cmd, a, b);
	}
}
