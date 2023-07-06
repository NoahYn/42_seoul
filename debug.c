/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:30:27 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 23:21:51 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
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
