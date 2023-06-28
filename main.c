/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 21:41:37 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		max_element(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (arr[i] < arr[j])
				break;
		}
		if (j == size)
		{
			arr[i] = INTMIN;
			return (i+1);
		}
	}
	return (0);
}

int		min_element(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (arr[i] > arr[j])
				break;
		}
		if (j == size)
		{
			arr[i] = INTMAX;
			return (i+1);
		}
	}
	return (0);
}

void	merge_tri_A2B(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
{
	if (seq == 1)
	{
		pb(cmd, a, b);
	}
	else if (seq == 2)
	{
		rra(cmd, a, b);
		pb(cmd, a, b);
	}
	else if (seq == 3)
	{
		rrb(cmd, a, b);
	}
}

void	merge_tri_B2A(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
{
	if (seq == 1)
	{
		pa(cmd, a, b);
	}
	else if (seq == 2)
	{
		rrb(cmd, a, b);
		pa(cmd, a, b);
	}
	else if (seq == 3)
	{
		rra(cmd, a, b);
	}
}

void	a2b(t_cmd *cmd, t_stack *a, t_stack *b)
{
	int	i;
	int	one_third;
	int sequence;
	int tri[3];
	int step;

	// push quater func
	one_third = a->size / 3;
	i = 0;
	while (i++ < one_third)
		pb(cmd, a, b);
	ft_printf("after pb one third\n");
	print(a, b);
	step = 0;
	while (a->size > 0)
	{
		step++;
		sequence = 0;
		// init rect func
		tri[0] = a->top->item;
		tri[1] = a->bottom->item;
		tri[2] = b->bottom->item;
		ft_printf("%d, %d, %d\n", tri[0], tri[1], tri[2]);
		do
		{
			sequence *= 10;
			if (one_third-- > 0)
				sequence += min_element(tri, 4);
			else
				sequence += max_element(tri, 3);
		} while (sequence < 100);
//		ft_printf("%d\n", sequence);
		while (sequence > 0)
		{
			merge_tri_A2B(cmd, a, b, sequence % 10);
			sequence /= 10;
		}
		ft_printf("after one triangle\n");
		print(a, b);
	}
}

void	b2a(t_cmd *cmd, t_stack *a, t_stack *b)
{
	int	i;
	int	one_third;
	int sequence;
	int tri[3];
	int step;

	// push quater func
	one_third = b->size / 3;
	i = 0;
	while (i++ < one_third)
		pa(cmd, a, b);
	ft_printf("after pa one third\n");
	print(a, b);
	step = 0;
	while (b->size > 0)
	{
		step++;
		sequence = 0;
		// init rect func
		tri[0] = b->top->item;
		tri[1] = b->bottom->item;
		tri[2] = a->bottom->item;
		ft_printf("%d, %d, %d\n", tri[0], tri[1], tri[2]);
		do
		{
			sequence *= 10;
//			if (one_third-- > 0)
				sequence += min_element(tri, 3);
//			else
//				sequence += max_element(tri, 3);
		} while (sequence < 100);
//		ft_printf("%d\n", sequence);
		while (sequence > 0)
		{
			merge_tri_B2A(cmd, a, b, sequence % 10);
			sequence /= 10;
		}
		ft_printf("after one triangle\n");
		print(a, b);
	}
}


int get_totalcmd(t_cmd *cmd)
{
	int	cnt;

	cnt = 0;
	cnt += cmd->pa;
	cnt += cmd->pb;
	cnt += cmd->sa;
	cnt += cmd->sb;
	cnt += cmd->ss;
	cnt += cmd->ra;
	cnt += cmd->rb;
	cnt += cmd->rr;
	cnt += cmd->rra;
	cnt += cmd->rrb;
	cnt += cmd->rrr;
	return (cnt);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_cmd cmd;

	init(&cmd, &a, &b);
	check_err(argc, argv, &a);
	ft_printf("inv_cnt = %d\nbefore sort\n", cnt_inverse_order(&a));
	print(&a, &b);
	a2b(&cmd, &a, &b);
	b2a(&cmd, &a, &b);
	ft_printf("total = %d\n", get_totalcmd(&cmd));
}


/*
step 1 -> 스택a의 요소 중 1/3을 스택b로 푸시
	b로 푸시하는 과정에서 정렬? 내림차순으로
a : 1 9 4 | 2 5 3 7 8 6 0
pb pb pb

step 2 -> a의 양끝과 b의 끝 총 세 요소를 비교하여 b의 탑에 정렬
a : 2/ 5 3 7 8 6 0/
b : 4 9 1/
rra pb

a : 2/ 5 3 7 8 6/
b : 0 | 4 9 1/
rrb

a : 2/ 5 3 7 8 6/
b : 1 0 | 4 9/
pb

a : 5/ 3/ 7 8 6/
b : 2 1 0 | 4 9/
pb pb

a : 7/ 8 6/
b : 3 5 2 1 0 | 4 9/
rra pb pb pb rrb

a :  
b : 9 8 7 6 3 5 2 1 0 | 4


*/