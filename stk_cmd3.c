#include "push_swap.h"

void	rra(t_cmd *cmd, t_stack *a, t_stack *b)
{
	b->size = b->size;
	reverse_rotate(a);
	cmd->rra++;
	ft_printf("rra\n");
}

void	rrb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	a->size = a->size;
	reverse_rotate(b);
	cmd->rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_cmd *cmd, t_stack *a, t_stack *b)
{
	rra(cmd, a, b);
	rrb(cmd, a, b);
	cmd->rrr++;
	ft_printf("rrr\n");
}
