/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:10:07 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 21:40:58 by sunyoon          ###   ########.fr       */
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
	int		flag;
	char	**split;

	split = ft_split(cmdset, ' ');
	i = -1;
	flag = 0;
	while (split[++i])
	{
		if (ft_strncmp(split[i], "pa", 2) == 0)
			pa(cmd, a, b);
		else if (ft_strncmp(split[i], "pb", 2) == 0)
			pb(cmd, a, b);
		else if (ft_strncmp(split[i], "sa", 2) == 0)
			sa(cmd, a, b);
		else if (ft_strncmp(split[i], "sb", 2) == 0)
			sb(cmd, a, b);
		else if (ft_strncmp(split[i], "ra", 2) == 0)
			ra(cmd, a, b);
		else if (ft_strncmp(split[i], "rb", 2) == 0)
			rb(cmd, a, b);
		else if (ft_strncmp(split[i], "rra", 3) == 0)
			rra(cmd, a, b);
		else if (ft_strncmp(split[i], "rrb", 3) == 0)
			rrb(cmd, a, b);
		else if (ft_strncmp(split[i], "rrr", 3) == 0)
		{
			rra(cmd, a, b);
			rrb(cmd, a, b);
		}
		else if (ft_strncmp(split[i], "rr", 2) == 0)
		{
			ra(cmd, a, b);
			rb(cmd, a, b);
		}
		else if (ft_strncmp(split[i], "ss", 2) == 0)
		{
			sa(cmd, a, b);
			sb(cmd, a, b);
		}
		else
		{
			flag = 1;
			break ;
		}
		free(split[i]);
	}
	free(split);
	if (flag)
	{
		ft_printf("Error\n");
		exit_program(cmd, a, b, 0);
	}
}
