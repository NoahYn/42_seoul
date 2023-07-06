/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:44 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 20:48:26 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;

	if (a->size < 2)
		return ;
	rotate(a);
	if (ft_strncmp(cmd->last->cmd, "rra", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	if (ft_strncmp(cmd->last->cmd, "rb", 3) == 0)
	{
		ft_strlcpy(cmd->last->cmd, "rr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(cmd, a, b, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "ra", 4);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}

void	rb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;

	if (b->size < 2)
		return ;
	rotate(b);
	if (ft_strncmp(cmd->last->cmd, "rra", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	if (ft_strncmp(cmd->last->cmd, "ra", 3) == 0)
	{
		ft_strlcpy(cmd->last->cmd, "rr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(cmd, a, b, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "rb", 4);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}

void	rra(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;

	if (a->size < 2)
		return ;
	reverse_rotate(a);
	if (ft_strncmp(cmd->last->cmd, "ra", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	if (ft_strncmp(cmd->last->cmd, "rrb", 4) == 0)
	{
		ft_strlcpy(cmd->last->cmd, "rrr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(cmd, a, b, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "rra", 4);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}

void	rrb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;

	if (b->size < 2)
		return ;
	reverse_rotate(b);
	if (ft_strncmp(cmd->last->cmd, "rb", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	if (ft_strncmp(cmd->last->cmd, "rra", 4) == 0)
	{
		ft_strlcpy(cmd->last->cmd, "rrr", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit_program(cmd, a, b, 0);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "rrb", 4);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}
