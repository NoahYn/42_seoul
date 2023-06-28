/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 12:40:16 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	init(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->top = NULL;
	a->bottom = NULL;
	b->size = 0;
	b->top = NULL;
	b->bottom = NULL;
}


int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
//	t_cmd cmd;

	init(&a, &b);
	check_err(argc, argv, &a);
	ft_printf("cnt = %d\n", cnt_inverse_order(&a));
	print(&a, &b);
}
