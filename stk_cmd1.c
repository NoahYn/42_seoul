#include "push_swap.h"

void	pa(t_cmd *cmd, t_stack *a, t_stack *b)
{
	push(a, pop(b));
	cmd->pa++;
	ft_printf("pa\n");
}

void	pb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	push(b, pop(a));
	cmd->pb++;
	ft_printf("pb\n");
}

void	sa(t_cmd *cmd, t_stack *a)
{
	swap(a);
	cmd->sa++;
	ft_printf("sa\n");
}

void	sb(t_cmd *cmd, t_stack *b)
{
	swap(b);
	cmd->sb++;
	ft_printf("sb\n");
}

void	ss(t_cmd *cmd, t_stack *a, t_stack *b)
{
	sa(cmd, a);
	sb(cmd, b);
	cmd->ss++;
	ft_printf("ss\n");
}

