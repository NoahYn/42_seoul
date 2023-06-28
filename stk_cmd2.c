#include "push_swap.h"

void	ra(t_cmd *cmd, t_stack *a, t_stack *b)
{
	b->size = b->size;
	rotate(a);
	cmd->ra++;
	ft_printf("ra\n");
}

void	rb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	a->size = a->size;
	rotate(b);
	cmd->rb++;
	ft_printf("rb\n");
}

void	rr(t_cmd *cmd, t_stack *a, t_stack *b)
{
	ra(cmd, a, b);
	rb(cmd, a, b);
	cmd->rr++;
	ft_printf("rr\n");
}