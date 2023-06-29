#include "push_swap.h"

void	cmd_multiply(char *cmdset, int num, t_cmd *cmd, t_stack *a, t_stack *b)
{
	while (num--)
	{
		if (ft_strncmp(cmdset, "pa", 4) == 0)
			pa(cmd, a, b);
		else if (ft_strncmp(cmdset, "pb", 4) == 0)
			pb(cmd, a, b);
		else if (ft_strncmp(cmdset, "sa", 4) == 0)
			sa(cmd, a, b);
		else if (ft_strncmp(cmdset, "sb", 4) == 0)
			sb(cmd, a, b);
		else if (ft_strncmp(cmdset, "ra", 4) == 0)
			ra(cmd, a, b);
		else if (ft_strncmp(cmdset, "rb", 4) == 0)
			rb(cmd, a, b);
		else if (ft_strncmp(cmdset, "rra", 4) == 0)
			rra(cmd, a, b);
		else if (ft_strncmp(cmdset, "rrb", 4) == 0)
			rrb(cmd, a, b);
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
