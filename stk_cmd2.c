#include "push_swap.h"

void	ra(t_cmd *cmd, t_stack *a)
{
	rotate(a);
	cmd->ra++;
	ft_printf("ra\n");
}

void	rb(t_cmd *cmd, t_stack *b)
{
	rotate(b);
	cmd->rb++;
	ft_printf("rb\n");
}

void	rr(t_cmd *cmd, t_stack *a, t_stack *b)
{
	ra(cmd, a);
	rb(cmd, b);
	cmd->rr++;
	ft_printf("rr\n");
}