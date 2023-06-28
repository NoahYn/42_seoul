/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 15:58:57 by sunyoon          ###   ########.fr       */
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

void	merge_rect_B(t_cmd *cmd, t_stack *a, t_stack *b, int seq, int *sapb)
{
	if (seq == 1 || (seq == 2 && *sapb == 0))
	{
		pb(cmd, a, b);
		*sapb = 0;
	}
	else if (seq == 2)
	{
		sa(cmd, a, b);
		pb(cmd, a, b);
	}
	else if (seq == 3)
	{
		rra(cmd, a, b);
		pb(cmd, a, b);
	}
	else if (seq == 4)
	{
		rrb(cmd, a, b);
	}
}

void	a2b(t_cmd *cmd, t_stack *a, t_stack *b)
{
	int	quater;
	int sequence;
	int rect[4];
	int sapb;

	// push quater func
	quater = a->size / 4;
	while (quater--)
		pb(cmd, a, b);
	ft_printf("after pb quater\n");
	print(a, b);
	while (a->size > 2)
	{
		sequence = 0;
		// init rect func
		rect[0] = a->top->item;
		rect[1] = a->top->prev->item;
		rect[2] = a->bottom->item;
		rect[3] = b->bottom->item;
//		ft_printf("%d, %d, %d, %d\n", rect[0], rect[1], rect[2], rect[3]);
		do
		{
			sequence *= 10;
			sequence += min_element(rect, 4);
		} while (sequence < 1000);
		sapb = 1;
//		ft_printf("%d\n", sequence);
		while (sequence > 0)
		{
			merge_rect_B(cmd, a, b, sequence % 10, &sapb);
			sequence /= 10;
		}
		ft_printf("after one rect\n");
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