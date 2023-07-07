/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_cmd1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:48:46 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:57:17 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->b.size == 0)
		return ;
	push(ps, &ps->a, pop(&ps->b));
	if (ft_strncmp(ps->cmd.last->cmd, "pb", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "pa", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}

void	pb(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->a.size == 0)
		return ;
	push(ps, &ps->b, pop(&ps->a));
	if (ft_strncmp(ps->cmd.last->cmd, "pa", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "pb", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}

void	sa(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->a.size < 2)
		return ;
	swap(&ps->a);
	if (ft_strncmp(ps->cmd.last->cmd, "sa", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	if (ft_strncmp(ps->cmd.last->cmd, "sb", 3) == 0)
	{
		ft_strlcpy(ps->cmd.last->cmd, "ss", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "sa", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}

void	sb(t_pushswap *ps)
{
	t_node2	*newcmd;

	if (ps->b.size < 2)
		return ;
	swap(&ps->b);
	if (ft_strncmp(ps->cmd.last->cmd, "sb", 3) == 0)
	{
		ps->cmd.last = ps->cmd.last->prev;
		free(ps->cmd.last->next);
		ps->cmd.last->next = NULL;
		return ;
	}
	if (ft_strncmp(ps->cmd.last->cmd, "sa", 3) == 0)
	{
		ft_strlcpy(ps->cmd.last->cmd, "ss", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(ps, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "sb", 4);
	ps->cmd.last->next = newcmd;
	newcmd->prev = ps->cmd.last;
	ps->cmd.last = newcmd;
}
