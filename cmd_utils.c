/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:10:07 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 00:32:41 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_cmd *cmd)
{
	t_node2	*curr;

	curr = cmd->first->next;
	while (curr)
	{
		ft_printf("%s\n", curr->cmd);
		curr = curr->next;
	}
}

void	do_cmds(t_pushswap *ps, char *cmdset, int num)
{
	int	i;

	ps->split = ft_split(cmdset, ' ');
	while (num--)
	{
		i = -1;
		while (ps->split[++i])
		{
			if (ft_strncmp(ps->split[i], "pa", 2) == 0)
				pa(ps);
			else if (ft_strncmp(ps->split[i], "pb", 2) == 0)
				pb(ps);
			else if (ft_strncmp(ps->split[i], "sa", 2) == 0)
				sa(ps);
			else if (ft_strncmp(ps->split[i], "sb", 2) == 0)
				sb(ps);
			else if (ft_strncmp(ps->split[i], "ra", 2) == 0)
				ra(ps);
			else if (ft_strncmp(ps->split[i], "rb", 2) == 0)
				rb(ps);
			else if (ft_strncmp(ps->split[i], "rra", 3) == 0)
				rra(ps);
			else if (ft_strncmp(ps->split[i], "rrb", 3) == 0)
				rrb(ps);
			else if (ft_strncmp(ps->split[i], "rrr", 3) == 0)
				do_cmds(ps, "rra rrb", 1);
			else if (ft_strncmp(ps->split[i], "rr", 2) == 0)
				do_cmds(ps, "ra rb", 1);
			else if (ft_strncmp(ps->split[i], "ss", 2) == 0)
				do_cmds(ps, "sa sb", 1);
			else
				exit_program(ps, "Error\n");
		}
	}
	free_split(ps->split);
}
