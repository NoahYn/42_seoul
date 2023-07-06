/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:04:31 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 23:52:35 by sunyoon          ###   ########.fr       */
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

void	init_triunit_b(t_pushswap *ps)
{
	int			vtx[6];
	int			size[6];
	int			i;
	int			j;

	i = -1;
	while (++i < ps->tri.num)
	{
		j = -1;
		while (++j < 6)
			size[j] = 1;
		j = 0;
		while (j++ < ps->tri.chunk[i])
		{
			if (ps->a.size > 0)
			{
				vtx[0] = AT;
				vtx[1] = AB;
				vtx[3] = AT;
				vtx[4] = AB;
			}
			else
			{
				size[0] = 0;
				size[1] = 0;
				size[3] = 0;
				size[4] = 0;
			}
			if (ps->a.size > 1)
			{
				if (size[0] == 1)
					vtx[3] = AS;
				if (size[1] == 1)
					vtx[4] = AB2;
			}
			if (ps->b.size > 0)
			{
				vtx[2] = BB;
				vtx[5] = BB;
			}
			else
			{
				size[2] = 0;
				size[5] = 0;
			}
			if (ps->b.size > 1 && size[2] == 1)
				vtx[5] = BB2;
			if (ps->tri.order[i] == DEC)
				merge_aab(ps, min_element(ps->tri.chunk[i], vtx, size));
			else
				merge_aab(ps, max_element(ps->tri.chunk[i], vtx, size));
		}
	}
}

void	init_triunit_a(t_pushswap *ps)
{
	int			vtx[6];
	int			size[6];
	int			i;
	int			j;

	i = -1;
	while (++i < ps->tri.num)
	{
		j = -1;
		while (++j < 6)
			size[j] = 1;
		j = 0;
		while (j++ < ps->tri.chunk[i])
		{
			if (ps->b.size > 0)
			{
				vtx[0] = BT;
				vtx[1] = BB;
				vtx[3] = BT;
				vtx[4] = BB;
			}
			else
			{
				size[0] = 0;
				size[1] = 0;
				size[3] = 0;
				size[4] = 0;
			}
			if (ps->a.size > 0)
			{
				vtx[2] = AB;
				vtx[5] = AB;
			}
			else
			{
				size[2] = 0;
				size[5] = 0;
			}
			if (ps->b.size > 1)
			{
				if (size[0] == 1)
					vtx[3] = BS;
				if (size[1] == 1)
					vtx[4] = BB2;
			}
			if (ps->a.size > 1 && size[2] == 1)
				vtx[5] = AB2;
			if (ps->tri.order[i] == DEC)
				merge_bba(ps, min_element(ps->tri.chunk[i], vtx, size));
			else
				merge_bba(ps, max_element(ps->tri.chunk[i], vtx, size));
		}
	}
}
