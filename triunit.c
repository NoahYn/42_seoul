/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:29:59 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:56:59 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_vtx_a(t_pushswap *ps, int vtx[6], int size[6])
{
	if (ps->b.size > 0)
	{
		vtx[0] = ps->b.top->item;
		vtx[1] = ps->b.bottom->item;
		vtx[3] = ps->b.top->item;
		vtx[4] = ps->b.bottom->item;
	}
	if (ps->a.size > 0)
	{
		vtx[2] = ps->a.bottom->item;
		vtx[5] = ps->a.bottom->item;
	}
	if (ps->b.size > 1)
	{
		if (size[0] == 1)
			vtx[3] = ps->b.top->prev->item;
		if (size[1] == 1)
			vtx[4] = ps->b.bottom->next->item;
	}
	if (ps->a.size > 1 && size[2] == 1)
		vtx[5] = ps->a.bottom->next->item;
}

void	set_vtx_b(t_pushswap *ps, int vtx[6], int size[6])
{
	if (ps->a.size > 0)
	{
		vtx[0] = ps->a.top->item;
		vtx[1] = ps->a.bottom->item;
		vtx[3] = ps->a.top->item;
		vtx[4] = ps->a.bottom->item;
	}
	if (ps->a.size > 1)
	{
		if (size[0] == 1)
			vtx[3] = ps->a.top->prev->item;
		if (size[1] == 1)
			vtx[4] = ps->a.bottom->next->item;
	}
	if (ps->b.size > 0)
	{
		vtx[2] = ps->b.bottom->item;
		vtx[5] = ps->b.bottom->item;
	}
	if (ps->b.size > 1 && size[2] == 1)
		vtx[5] = ps->b.bottom->next->item;
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
			set_vtx_b(ps, vtx, size);
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
			set_vtx_a(ps, vtx, size);
			if (ps->tri.order[i] == DEC)
				merge_bba(ps, min_element(ps->tri.chunk[i], vtx, size));
			else
				merge_bba(ps, max_element(ps->tri.chunk[i], vtx, size));
		}
	}
}
