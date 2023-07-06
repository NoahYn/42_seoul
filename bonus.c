/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:03:00 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 17:03:26 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	t_cmd	c;
	int		i;
	
	init(&c, &a, &b);
	i = 0;
	while (argv[++i])
	{
		do_cmds(argv[i], &c, &a, &b);
	}
	if (b.size == 0 && cnt_inverse_order(&a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}