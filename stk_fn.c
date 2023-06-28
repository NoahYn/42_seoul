/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:11:06 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 12:21:14 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stk, int item)
{
	t_node	*push_node;

	push_node = (t_node *)malloc(sizeof(t_node));
	if (!push_node)
		exit(1);
	if (stk->size++ > 0)
		stk->top->next = push_node;
	push_node->item = item;
	push_node->next = NULL;
	push_node->prev = stk->top;
	stk->top = push_node;
	if (stk->bottom == NULL)
		stk->bottom = push_node;
}

int	pop(t_stack *stk)
{
	t_node	*pop_node;
	int		pop_item;

	if (stk->size == 1)
		stk->bottom = NULL;
	pop_node = stk->top;
	pop_item = pop_node->item;
	stk->top = stk->top->prev;
	stk->top->next = NULL;
	free(pop_node);
	return (pop_item);
}

void	swap(t_stack *stk)
{
	int	temp;

	if (stk->size > 1)
	{
		temp = stk->top->item;
		stk->top->item = stk->top->prev->item;
		stk->top->prev->item = temp;
	}
}

void	rotate(t_stack *stk)
{
	stk->top->next = stk->bottom;
	stk->bottom->prev = stk->top;
	stk->bottom = stk->top;
	stk->top = stk->top->prev;
	stk->top->next = 0;
	stk->bottom->prev = 0;
}

void	reverse_rotate(t_stack *stk)
{
	stk->top->next = stk->bottom;
	stk->bottom->prev = stk->top;
	stk->top = stk->bottom;
	stk->bottom = stk->bottom->next;
	stk->bottom->prev = 0;
	stk->top->next = 0;
}
