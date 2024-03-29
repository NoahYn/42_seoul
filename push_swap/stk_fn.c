/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:11:06 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:57:32 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pushswap *ps, t_stack *stk, int item)
{
	t_node	*push_node;

	push_node = (t_node *)malloc(sizeof(t_node));
	if (!push_node)
		exit_program(ps, 0);
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

	if (stk->size-- == 1)
		stk->bottom = NULL;
	pop_node = stk->top;
	pop_item = pop_node->item;
	stk->top = stk->top->prev;
	if (stk->top)
		stk->top->next = NULL;
	free(pop_node);
	pop_node = 0;
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

// down(bottom to top)
void	rotate(t_stack *stk)
{
	if (stk->size == 0)
		return ;
	stk->top->next = stk->bottom;
	stk->bottom->prev = stk->top;
	stk->bottom = stk->top;
	stk->top = stk->top->prev;
	stk->top->next = 0;
	stk->bottom->prev = 0;
}

// up(top to bottom)
void	reverse_rotate(t_stack *stk)
{
	if (stk->size == 0)
		return ;
	stk->top->next = stk->bottom;
	stk->bottom->prev = stk->top;
	stk->top = stk->bottom;
	stk->bottom = stk->bottom->next;
	stk->bottom->prev = 0;
	stk->top->next = 0;
}
