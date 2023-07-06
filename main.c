/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 22:26:11 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_triangle	tri;
	int			num;
	int			i;

	if (a->size <= 5)
	{
		sort_small_a(cmd, a, b);
		return ;
	}
	tri.depth = 1;
	while (ft_pow(3, tri.depth -1) * 18 < a->size)
		tri.depth++;
	tri.num = ft_pow(3, tri.depth);
	num = a->size;
	tri.chunk = (int *)malloc(sizeof(int) * tri.num);
	tri.order = (int *)malloc(sizeof(int) * tri.num);
	tri.push_cnt = 0;
	i = -1;
	if (tri.depth % 2 == 0)
		cmd_multiply("pb", a->size, cmd, a, b);
	while (num > 0)
	{
		++i;
		tri.chunk[i] = num / (tri.num - i);
		num -= num / (tri.num - i);
		if (i >= tri.num / 3 * 2)
			tri.push_cnt += tri.chunk[i];
		if (tri.chunk[i] > 2)
		{
			if (tri.depth % 2 == 1)
				cmd_multiply("pb", tri.chunk[i] / 3, cmd, a, b);
			else
				cmd_multiply("pa", tri.chunk[i] / 3, cmd, a, b);
		}
	}
	tri.order[0] = INC;
	num = -1;
	while (ft_pow(3, ++num) < tri.num)
	{
		i = -1;
		while (++i < ft_pow(3, num))
		{
			tri.order[ft_pow(3, num) * 2 - i -1] = tri.order[i] * -1;
			tri.order[ft_pow(3, num) * 3 - i -1] = tri.order[i] * -1;
		}
	}
	if (tri.depth % 2 == 1)
		init_triunit_b(cmd, a, b, &tri);
	else
		init_triunit_a(cmd, a, b, &tri);
	while (tri.depth--)
	{
		if (tri.depth % 2 == 1)
			merge_a2b(cmd, a, b, &tri);
		else
			merge_b2a(cmd, a, b, &tri);
	}
}

void leak()
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_pushswap	ps;

	atexit(leak);
	if (argc < 2)
		exit(1);
	init(&ps);
	check_err(&ps.cmd, &(ps.a), &(ps.b), argv);
	if (cnt_inverse_order(&ps.a) == 0)
		exit_program(&ps.cmd, &ps.a, &ps.b, 0);
	sort_stack(&ps.cmd, &ps.a, &ps.b);
	print_cmd(&ps.cmd);
	exit_program(&ps.cmd, &ps.a, &ps.b, 0);
}
