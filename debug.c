#include "push_swap.h"

void print(t_stack *a, t_stack *b)
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
}