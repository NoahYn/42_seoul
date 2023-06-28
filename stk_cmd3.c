#include "push_swap.h"

void	rra(t_cmd *cmd, t_stack *a)
{
	reverse_rotate(a);
	cmd->rra++;
	ft_printf("rra\n");
}

void	rrb(t_cmd *cmd, t_stack *b)
{
	reverse_rotate(b);
	cmd->rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_cmd *cmd, t_stack *a, t_stack *b)
{
	rra(cmd, a);
	rrb(cmd, b);
	cmd->rrr++;
	ft_printf("rrr\n");
}
