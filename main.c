/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/30 02:46:02 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
void	cmd_multiply(char *cmdset, int num, t_cmd *cmd, t_stack *a, t_stack *b)
{
	while (num--)
	{
		if (ft_strncmp(cmdset, "pa", 4) == 0)
			pa(cmd, a, b);
		else if (ft_strncmp(cmdset, "pb", 4) == 0)
			pb(cmd, a, b);
		else if (ft_strncmp(cmdset, "sa", 4) == 0)
			sa(cmd, a, b);
		else if (ft_strncmp(cmdset, "sb", 4) == 0)
			sb(cmd, a, b);
		else if (ft_strncmp(cmdset, "ra", 4) == 0)
			ra(cmd, a, b);
		else if (ft_strncmp(cmdset, "rb", 4) == 0)
			rb(cmd, a, b);
		else if (ft_strncmp(cmdset, "rra", 4) == 0)
			rra(cmd, a, b);
		else if (ft_strncmp(cmdset, "rrb", 4) == 0)
			rrb(cmd, a, b);
	}	
}

void	do_cmds(char *cmdset, t_cmd *cmd, t_stack *a, t_stack *b)
{
	int		i;
	char	**split;

	split = ft_split(cmdset, ' ');
	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(split[i], "pa", 4) == 0)
			pa(cmd, a, b);
		else if (ft_strncmp(split[i], "pb", 4) == 0)
			pb(cmd, a, b);
		else if (ft_strncmp(split[i], "sa", 4) == 0)
			sa(cmd, a, b);
		else if (ft_strncmp(split[i], "sb", 4) == 0)
			sb(cmd, a, b);
		else if (ft_strncmp(split[i], "ra", 4) == 0)
			ra(cmd, a, b);
		else if (ft_strncmp(split[i], "rb", 4) == 0)
			rb(cmd, a, b);
		else if (ft_strncmp(split[i], "rra", 4) == 0)
			rra(cmd, a, b);
		else if (ft_strncmp(split[i], "rrb", 4) == 0)
			rrb(cmd, a, b);
		free(split[i]);
	}
	free(split);
}


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

void	a2b(t_cmd *cmd, t_stack *a, t_stack *b, int tri_size)
{
	int			i;
	int			j;
	int			one_third;
	t_triangle	tri;

	// push quater func
	one_third = a->size / 3;
	cmd_multiply("pb", one_third, cmd, a, b);
	ft_printf("after pb one third\n");
	print(a, b);

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
				tri.vertex[0] = B1;
			if (tri.vtx_size[1] > 0)
				tri.vertex[1] = B2;
			if (tri.vtx_size[2] > 0)
				tri.vertex[2] = B3;
			if (tri.order == 0)
				merge_tri_A2B(cmd, a, b, max_element(&tri));
			else
				merge_tri_A2B(cmd, a, b, min_element(&tri));
		} 	
		ft_printf("after one triangle\n");
		print(a, b);
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
	ft_printf("after pa one third\n");
	print(a, b);

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
				tri.vertex[0] = A1;
			if (tri.vtx_size[1] > 0)
				tri.vertex[1] = A2;
			if (tri.vtx_size[2] > 0)
				tri.vertex[2] = A3;
			if (tri.order == 0)
				merge_tri_B2A(cmd, a, b, max_element(&tri));
			else
				merge_tri_B2A(cmd, a, b, min_element(&tri));
		} 	
		ft_printf("after one triangle\n");
		print(a, b);
	}
}

void	sort_three_a(t_cmd *cmd, t_stack *a, t_stack *b)
{
	if (T1 < T2 && T1 < T3)
	{
		if (T2 < T3)
			return;
		sa(cmd, a, b);
	}
	if (T1 > T2 && T1 > T3)
	{
		if (T2 < T3)
			ra(cmd, a, b);
		else
			do_cmds("sa rra", cmd, a, b);
	}
	else
	{
		if (T2 < T3)
			sa(cmd, a, b);
		else
			rra(cmd, a, b);
	}
}

void	find_min(int min_idx[2], t_stack *stk)
{
	int min[2];
	int	idx;
	t_node *curr;

	curr = stk->top;
	min[0] = INTMAX;
	min[1] = INTMAX;
	min_idx[0] = -1;
	min_idx[1] = -1;
	idx = 0;
	while (curr)
	{
		idx++;
		if (min[0] > curr->item)
		{
			min[1] = min[0];
			min_idx[1] = min_idx[0];
			min[0] = curr->item;
			min_idx[0] = idx; 
		}
		else if (min[1] > curr->item)
		{
			min[1] = curr->item;
			min_idx[1] = idx;
		}
		curr = curr->prev;
	}
}

void	pb_min(t_cmd *cmd, t_stack *a, t_stack *b, int num)
{
	int min_idx[2];

	find_min(min_idx, a);
	if (num == 2)
	{
		if (min_idx[0] == 1 || min_idx[1] == 1) ;
		else if (min_idx[0] == 2 || min_idx[2] == 2)
			ra(cmd, a, b);
		else if (min_idx[0] == 5 || min_idx[2] == 5)
			rra(cmd, a, b);
		else
			cmd_multiply("ra", 2, cmd, a, b);
		pb(cmd, a, b);
	}
	find_min(min_idx, a);
	if (min_idx[0] == 4)
		rra(cmd, a, b);
	else
		while (min_idx[0]-- > 1)
			ra(cmd, a, b);
	pb(cmd, a, b);
}

void	sort_small(t_cmd *cmd, t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(cmd, a, b);
	else if (a->size == 3)
		sort_three_a(cmd, a, b);
	else
	{
		pb_min(cmd, a, b, a->size - 3);
		print(a, b);
		sort_three_a(cmd, a, b);
		print(a, b);
		if (b->size == 2 && b->top->item < b->top->prev->item)
			sb(cmd, a, b);
		print(a, b);
		cmd_multiply("pa", b->size, cmd, a, b);
	}
}

void	sort_stack(t_cmd *cmd, t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small(cmd, a, b);
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

void	print_cmd(t_cmd *cmd)
{
	t_node2 *curr;

	curr = cmd->first->next;
	while (curr)
	{
		ft_printf("%s\n", curr->cmd);
		curr = curr->next;
	}
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
	sort_stack(&cmd, &a, &b);
	ft_printf("inv_cnt = %d\nafter sort\n", cnt_inverse_order(&a));
	print(&a, &b);
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