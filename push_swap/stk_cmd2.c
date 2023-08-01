/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:44 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:55:26 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->a.size < 2)
		return ;
	rotate(&ps->a);
	if (ft_strncmp(ps->cmd.last->cmd, "rra", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	if (ft_strncmp(ps->cmd.last->cmd, "rb", 3) == 0)
	{
		ft_strlcpy(ps->cmd.last->cmd, "rr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "ra", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}

void	rb(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->b.size < 2)
		return ;
	rotate(&ps->b);
	if (ft_strncmp(ps->cmd.last->cmd, "rra", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	if (ft_strncmp(ps->cmd.last->cmd, "ra", 3) == 0)
	{
		ft_strlcpy(ps->cmd.last->cmd, "rr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "rb", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}

void	rra(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->a.size < 2)
		return ;
	reverse_rotate(&ps->a);
	if (ft_strncmp(ps->cmd.last->cmd, "ra", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	if (ft_strncmp(ps->cmd.last->cmd, "rrb", 4) == 0)
	{
		ft_strlcpy(ps->cmd.last->cmd, "rrr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "rra", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}

void	rrb(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->b.size < 2)
		return ;
	reverse_rotate(&ps->b);
	if (ft_strncmp(ps->cmd.last->cmd, "rb", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	if (ft_strncmp(ps->cmd.last->cmd, "rra", 4) == 0)
	{
		ft_strlcpy(ps->cmd.last->cmd, "rrr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "rrb", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}
