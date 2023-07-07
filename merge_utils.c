/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:04:31 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 07:58:14 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_element(int num, int *arr, int *size)
{
	int	max;
	int	max_idx;
	int	i;

	i = -1;
	max = INTMIN;
	max_idx = -1;
	while (++i < num)
	{
		if (size[i] == 0)
			continue ;
		if (max < arr[i])
		{
			max = arr[i];
			max_idx = i;
		}
	}
	size[max_idx]--;
	if (max_idx >= 3 && size[max_idx -3] == 0)
		return (max_idx -2);
	return (max_idx +1);
}

int	min_element(int num, int *arr, int *size)
{
	int	min;
	int	min_idx;
	int	i;

	i = -1;
	min = INTMAX;
	min_idx = -1;
	while (++i < num)
	{
		if (size[i] == 0)
			continue ;
		if (min > arr[i])
		{
			min = arr[i];
			min_idx = i;
		}
	}
	size[min_idx]--;
	if (min_idx >= 3 && size[min_idx -3] == 0)
		return (min_idx -2);
	return (min_idx +1);
}

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
