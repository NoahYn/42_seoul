#include "push_swap.h"

void print_stack(t_stack *a, t_stack *b)
{
	int size = a->size;
	ft_printf("stack A : ");	
	while (size--)
	{
		ft_printf("%d ", a->top->item);
		rotate(a);
	}
	ft_printf("\nstack B : ");
	size = b->size;
	while (size--)
	{
		ft_printf("%d ", b->top->item);
		rotate(b);
	}
	ft_printf("\n\n");
}

void	print_cmd(t_cmd *cmd)
{
	t_node2 *curr;
	int num;

	curr = cmd->first->next;
	num = 0;
	while (curr)
	{
		num++;
		ft_printf("%s\n", curr->cmd);
		curr = curr->next;
	}
	ft_printf("cnt = %d\n", num);
}