/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:10:07 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 17:11:04 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_multiply(char *cmdset, int num, t_cmd *cmd, t_stack *a, t_stack *b)
{
	while (num--)
	{
		do_cmds(cmdset, cmd, a, b);
	}
}

void	do_cmds(char *cmdset, t_cmd *cmd, t_stack *a, t_stack *b)
{
	int		i;
	char	**split;

	split = ft_split(cmdset, ' ');
	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(split[i], "pa", 4) == 0)
			pa(cmd, a, b);
		else if (ft_strncmp(split[i], "pb", 4) == 0)
			pb(cmd, a, b);
		else if (ft_strncmp(split[i], "sa", 4) == 0)
			sa(cmd, a, b);
		else if (ft_strncmp(split[i], "sb", 4) == 0)
			sb(cmd, a, b);
		else if (ft_strncmp(split[i], "ra", 4) == 0)
			ra(cmd, a, b);
		else if (ft_strncmp(split[i], "rb", 4) == 0)
			rb(cmd, a, b);
		else if (ft_strncmp(split[i], "rra", 4) == 0)
			rra(cmd, a, b);
		else if (ft_strncmp(split[i], "rrb", 4) == 0)
			rrb(cmd, a, b);
		free(split[i]);
	}
	free(split);
}
