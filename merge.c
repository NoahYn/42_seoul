/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:12:40 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 17:16:58 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_aab(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
{
	if (seq == 1)
		pb(cmd, a, b);
	else if (seq == 2)
		do_cmds("rra pb", cmd, a, b);
	else if (seq == 3)
		rrb(cmd, a, b);
	else if (seq == 4)
		do_cmds("sa pb", cmd, a, b);
	else if (seq == 5)
		do_cmds("rra rra pb ra", cmd, a, b);
	else if (seq == 6)
		do_cmds("rrb rrb sb rb", cmd, a, b);
}

void	merge_bba(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
{
	if (seq == 1)
		pa(cmd, a, b);
	else if (seq == 2)
		do_cmds("rrb pa", cmd, a, b);
	else if (seq == 3)
		rra(cmd, a, b);
	else if (seq == 4)
		do_cmds("sb pa", cmd, a, b);
	else if (seq == 5)
		do_cmds("rrb rrb pa rb", cmd, a, b);
	else if (seq == 6)
		do_cmds("rra rra sa ra", cmd, a, b);
}

void	merge_a2b(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	int		i;
	int		arr[3];
	int		size[3];

	cmd_multiply("pb", tri->push_cnt, cmd, a, b);
	tri->push_cnt = 0;
	tri->num /= 3;
	i = -1;
	while (++i < tri->num)
	{
		size[1] = tri->chunk[i];
		size[0] = tri->chunk[tri->num * 2 - i -1];
		size[2] = tri->chunk[tri->num * 3 - i -1];
		tri->chunk[i] = size[0] + size[1] + size[2];
		if (i >= tri->num / 3 * 2)
			tri->push_cnt += tri->chunk[i];
		while (size[0] || size[1] || size[2])
		{
			if (a->size > 0)
			{
				arr[0] = AT;
				arr[1] = AB;
			}
			if (b->size > 0)
				arr[2] = BB;
			if (tri->order[i] == DEC)
				merge_aab(cmd, a, b, min_element(3, arr, size));
			else
				merge_aab(cmd, a, b, max_element(3, arr, size));
		}
		print_stack(a, b);
	}
}

void	merge_b2a(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	int		i;
	int		arr[3];
	int		size[3];

	cmd_multiply("pa", tri->push_cnt, cmd, a, b);
	tri->push_cnt = 0;
	tri->num /= 3;
	i = -1;
	while (++i < tri->num)
	{
		size[1] = tri->chunk[i];
		size[0] = tri->chunk[tri->num * 2 - i -1];
		size[2] = tri->chunk[tri->num * 3 - i -1];
		tri->chunk[i] = size[0] + size[1] + size[2];
		if (i >= tri->num / 3 * 2)
			tri->push_cnt += tri->chunk[i];
		while (size[0] || size[1] || size[2])
		{
			if (b->size > 0)
			{
				arr[0] = BT;
				arr[1] = BB;
			}
			if (a->size > 0)
				arr[2] = AB;
			if (tri->order[i] == DEC)
				merge_bba(cmd, a, b, min_element(3, arr, size));
			else
				merge_bba(cmd, a, b, max_element(3, arr, size));
		}
		print_stack(a, b);
	}
}
