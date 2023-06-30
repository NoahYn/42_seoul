/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/30 13:40:13 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		max_element(t_triangle *tri)
{
	int max;
	int max_idx;
	int i;

	i = -1;
	max = INTMIN;
	max_idx = -1;
	while (++i < 3)
	{
		if (tri->vtx_size[i] == 0) continue;
		if (max < tri->vertex[i])
		{
			max = tri->vertex[i];
			max_idx = i;
		}
	}
	tri->vtx_size[max_idx]--;
	return (max_idx+1);
}

int		min_element(t_triangle *tri)
{
	int min;
	int min_idx;
	int i;

	i = -1;
	min = INTMAX;
	min_idx = -1;
	while (++i < 3)
	{
		if (tri->vtx_size[i] < 1) continue;
		if (min > tri->vertex[i])
		{
			min = tri->vertex[i];
			min_idx = i;
		}
	}
	if (min_idx > -1)
		tri->vtx_size[min_idx]--;
	return (min_idx+1);
}

void	merge_aab(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
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

void	merge_bba(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
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

void	a2b(t_cmd *cmd, t_stack *a, t_stack *b, int tri_size)
{
	int			i;
	int			j;
	int			one_third;
	t_triangle	tri;

	// push quater func
	one_third = a->size / 3;
	cmd_multiply("pb", one_third, cmd, a, b);
//	ft_printf("after pb one third\n");
//	print_stack(a, b);

	i = 0;
	while (i++ < one_third)
	{
		tri.vtx_size[0] = tri_size / 3;
		tri.vtx_size[1] = tri_size / 3;
		tri.vtx_size[2] = tri_size / 3;
		j = 0;
		if (a->size >= one_third * 2)
			tri.order = 0;
		else
			tri.order = 1;
		while (j++ < tri_size)
		{
			if (tri.vtx_size[0] > 0)
				tri.vertex[0] = BT;
			if (tri.vtx_size[1] > 0)
				tri.vertex[1] = BS;
			if (tri.vtx_size[2] > 0)
				tri.vertex[2] = BB;
			if (tri.order == 0)
				merge_aab(cmd, a, b, max_element(&tri));
			else
				merge_bba(cmd, a, b, min_element(&tri));
		} 	
//		ft_printf("after one triangle\n");
//		print_stack(a, b);
	}
}

void	b2a(t_cmd *cmd, t_stack *a, t_stack *b, int tri_size)
{
	int			i;
	int			one_third;
	t_triangle	tri;

	// push quater func
	one_third = b->size / 3;
	i = 0;
	cmd_multiply("pa", one_third, cmd, a, b);
//	ft_printf("after pa one third\n");
//	print_stack(a, b);

	while (b->size > 0)
	{
		tri.vtx_size[0] = tri_size / 3;
		tri.vtx_size[1] = tri_size / 3;
		tri.vtx_size[2] = tri_size / 3;
		i = 0;
		if (one_third > 0)
			tri.order = 0;
		else
			tri.order = 1;
		one_third -= tri_size;
		while (i++ < tri_size)
		{
			if (tri.vtx_size[0] > 0)
				tri.vertex[0] = AT;
			if (tri.vtx_size[1] > 0)
				tri.vertex[1] = AS;
			if (tri.vtx_size[2] > 0)
				tri.vertex[2] = AB;
			if (tri.order == 0)
				merge_bba(cmd, a, b, max_element(&tri));
			else
				merge_aab(cmd, a, b, min_element(&tri));
		} 	
//		ft_printf("after one triangle\n");
//		print_stack(a, b);
	}
}

void	make_triunit_a(t_cmd *cmd, t_stack *a, t_stack *b, int size, int order)
{
	if (size == 2)
	{
		if ((AT > AS && order == INC) || (AT < AS) && order == DEC)
			do_cmds("pb pb", cmd, a, b);
		else
			do_cmds("sa pb pb", cmd, a, b);
	}
	else if (size == 3)
	{
		if (order == INC)
		{
			if (AT > AS && AT > AB)
				
		}
		else
		{

		}
	}
}

void	init_triangle(t_cmd *cmd, t_stack *a, t_stack *b)
{
	int chunk[3];
	
	if (a->size < 12)
	{
		if (a->size < 9)
			chunk[0] = 3;
		else
			chunk[0] = a->size - 6;
		chunk[1] = (a->size - chunk[0]) / 2;
		chunk[2] = a->size - chunk[0] - chunk[1];
	}
	merge_aaa(cmd, a, b, chunk[1]);
	merge_aaa(cmd, a, b, chunk[2]);
	sort_small_a(cmd, a, b);
}

void	merge(t_cmd *cmd, t_stack *a, t_stack *b)
{

}

void	sort_stack(t_cmd *cmd, t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small_a(cmd, a, b);
	else if (a->size < 12)
	{
		init_triangle(cmd, a, b);
		merge(cmd, a, b);
	}
	else
	{

	a2b(cmd, a, b, 3);
//	if (cnt_inverse_order(b))
	if (b->size < 9)
	{
		
	}
	else
		b2a(cmd, a, b, 9);

	}
}



int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_cmd cmd;

	init(&cmd, &a, &b);
	check_err(argc, argv, &a);
//	ft_printf("inv_cnt = %d\nbefore sort\n", cnt_inverse_order(&a));
//	print_stack(&a, &b);
	sort_stack(&cmd, &a, &b);
//	ft_printf("inv_cnt = %d\nafter sort\n", cnt_inverse_order(&a));
//	print_stack(&a, &b);
	print_cmd(&cmd);

	// compress_cmd
	// print_cmd
	// exit_program (free, error handling)
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