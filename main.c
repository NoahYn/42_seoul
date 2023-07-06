/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 11:41:57 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		max_element(int num, int *arr, int *size)
{
	int max;
	int max_idx;
	int i;

	i = -1;
	max = INTMIN;
	max_idx = -1;
	while (++i < num)
	{
		if (size[i] == 0) continue;
		if (max < arr[i])
		{
			max = arr[i];
			max_idx = i;
		}
	}
	size[max_idx]--;
	if (max_idx >= 3 && size[max_idx-3] == 0)
		return (max_idx-2);
	return (max_idx+1);
}

int		min_element(int num, int *arr, int *size)
{
	int min;
	int min_idx;
	int i;

	i = -1;
	min = INTMAX;
	min_idx = -1;
	while (++i < num)
	{
		if (size[i] == 0) continue;
		if (min > arr[i])
		{
			min = arr[i];
			min_idx = i;
		}
	}
	size[min_idx]--;
	if (min_idx >= 3 && size[min_idx-3] == 0)
		return (min_idx-2);
	return (min_idx+1);
}
void	merge_aab(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
{
	if (seq == 1)
		pb(cmd, a, b);
	else if (seq == 2)
		do_cmds("rra pb", cmd, a, b);
	else if (seq == 3)
		rrb(cmd, a, b);
	else if (seq == 4)
		do_cmds("sa pb", cmd, a, b);
	else if (seq == 5)
		do_cmds("rra rra pb ra", cmd, a, b);
	else if (seq == 6)
		do_cmds("rrb rrb sb rb", cmd, a, b);
}

void	merge_bba(t_cmd *cmd, t_stack *a, t_stack *b, int seq)
{
	if (seq == 1)
		pa(cmd, a, b);
	else if (seq == 2)
		do_cmds("rrb pa", cmd, a, b);
	else if (seq == 3)
		rra(cmd, a, b);
	else if (seq == 4)
		do_cmds("sb pa", cmd, a, b);
	else if (seq == 5)
		do_cmds("rrb rrb pa rb", cmd, a, b);
	else if (seq == 6)
		do_cmds("rra rra sa ra", cmd, a, b);
}

void	merge_a2b(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	int		i;
	int		arr[3];
	int		size[3];

	cmd_multiply("pb", tri->push_cnt, cmd, a, b);
	tri->push_cnt = 0;
	tri->num /= 3;
	print_stack(a, b);

	i = -1;
	while (++i < tri->num)
	{
		size[1] = tri->chunk[i];
		size[0] = tri->chunk[tri->num*2 -1 -i];
		size[2] = tri->chunk[tri->num*3 -1 -i];
	
		tri->chunk[i] = size[0] + size[1] + size[2];
		if (i >= tri->num/3*2)
			tri->push_cnt += tri->chunk[i];
		//ft_printf("i = %d, order = %d\n", i, tri->order[i]);
		//ft_printf("size[0] = %d, size[1] = %d, size[2] = %d\n\n", size[0], size[1], size[2]);
		while (size[0] || size[1] || size[2])
		{
			if (a->size > 0)	
			{
				arr[0] = AT;
				arr[1] = AB;
			}
			if (b->size > 0)
				arr[2] = BB;

			if (tri->order[i] == DEC)
				merge_aab(cmd, a, b, min_element(3, arr, size));
			else
				merge_aab(cmd, a, b, max_element(3, arr, size));			
		}
		print_stack(a, b);
	}

}

void	merge_b2a(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	int		i;
	int		arr[3];
	int		size[3];

	cmd_multiply("pa", tri->push_cnt, cmd, a, b);
	tri->push_cnt = 0;
	tri->num /= 3;
	print_stack(a, b);

	i = -1;
	while (++i < tri->num)
	{
		size[1] = tri->chunk[i];
		size[0] = tri->chunk[tri->num*2 -1 -i];
		size[2] = tri->chunk[tri->num*3 -1 -i];

		tri->chunk[i] = size[0] + size[1] + size[2];
		if (i >= tri->num/3*2)
			tri->push_cnt += tri->chunk[i];
		//ft_printf("i = %d, order = %d\n", i, tri->order[i]);
		//ft_printf("size[0] = %d, size[1] = %d, size[2] = %d\n\n", size[0], size[1], size[2]);
		while (size[0] || size[1] || size[2])
		{
			if (b->size > 0)	
			{
				arr[0] = BT;
				arr[1] = BB;
			}
			if (a->size > 0)
				arr[2] = AB;
			if (tri->order[i] == DEC)
				merge_bba(cmd, a, b, min_element(3, arr, size));
			else
				merge_bba(cmd, a, b, max_element(3, arr, size));
		}
		print_stack(a, b);
	}
}

void	init_triangle_b(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	int			vtx[6];
	int			size[6];
	int			i;
	int			j;

	i = -1;
	while (++i < tri->num)
	{
		j = -1;
		while (++j < 6)
			size[j] = 1;
		j = 0;
			//ft_printf("chunk = %d\n", tri->chunk[i]);
		while (j++ < tri->chunk[i])
		{
			if (a->size > 0)
			{
				vtx[0] = AT;
				vtx[1] = AB;
				vtx[3] = AT;
				vtx[4] = AB;
			}
			else
			{
				size[0] = 0;
				size[1] = 0;
				size[3] = 0;
				size[4] = 0;
			}
			if (a->size > 1)
			{
				if (size[0] == 1)
					vtx[3] = AS;
				if (size[1] == 1)
					vtx[4] = AB2;
			}

			if (b->size > 0)
			{
				vtx[2] = BB;
				vtx[5] = BB;
			}
			else
			{
				size[2] = 0;
				size[5] = 0;
			}

			if (b->size > 1 && size[2] == 1)
				vtx[5] = BB2;
			int m;
			if (tri->order[i] == DEC)
				m = min_element(tri->chunk[i], vtx, size);
			else
				m = max_element(tri->chunk[i], vtx, size);
			//ft_printf("m = %d\n", m);
			merge_aab(cmd, a, b, m);
			print_stack(a, b);
		}
		//ft_printf("i = %d, dir = %s\n", i, ((tri->order[i] == 1) ? "INC" : "DEC"));
		print_stack(a, b);
	}
}

void	init_triangle_a(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	int			vtx[6];
	int			size[6];
	int			i;
	int			j;

	i = -1;
	while (++i < tri->num)
	{
		j = -1;
		while (++j < 6)
			size[j] = 1;
		j = 0;
		while (j++ < tri->chunk[i])
		{
			if (b->size > 0)
			{
				vtx[0] = BT;
				vtx[1] = BB;
				vtx[3] = BT;
				vtx[4] = BB;
			}
			else
			{
				size[0] = 0;
				size[1] = 0;
				size[3] = 0;
				size[4] = 0;
			}
			if (a->size > 0)
			{
				vtx[2] = AB;
				vtx[5] = AB;
			}
			else
			{
				size[2] = 0;
				size[5] = 0;
			}
			if (b->size > 1)
			{
				if (size[0] == 1)
					vtx[3] = BS;
				if (size[1] == 1)
					vtx[4] = BB2;
			}
			if (a->size > 1 && size[2] == 1)
				vtx[5] = AB2;
			if (tri->order[i] == DEC)
				merge_bba(cmd, a, b, min_element(tri->chunk[i], vtx, size));
			else
				merge_bba(cmd, a, b, max_element(tri->chunk[i], vtx, size));
		}
	}
}



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
	
	// depth is count to merge
	tri.depth = 1;
	while (ft_pow(3, tri.depth-1) * 18 < a->size)
		tri.depth++;
	// number of triangle
	tri.num = ft_pow(3, tri.depth);
	num = a->size;
	tri.chunk = (int *)malloc(sizeof(int) * tri.num);
	tri.order = (int *)malloc(sizeof(int) * tri.num);
	//ft_printf("depth = %d, number of tri = %d\n", tri.depth, tri.num);
	tri.push_cnt = 0;

	i = -1;
	if (tri.depth % 2 == 0)
		cmd_multiply("pb", a->size, cmd, a, b);
	while (num > 0)
	{
		++i;
		tri.chunk[i] = num/(tri.num-i);
		num -= num/(tri.num-i);

		if (i >= tri.num/3*2)
			tri.push_cnt += tri.chunk[i];
		//ft_printf("i = %d, tri.chunk[%d] = %d\n", i, i, tri.chunk[i]);
		if (tri.chunk[i] > 2)
		{
			if (tri.depth % 2 == 1)
				cmd_multiply("pb", tri.chunk[i]/3, cmd, a, b);
			else
				cmd_multiply("pa", tri.chunk[i]/3, cmd, a, b);
		}
	}
//	if (tri.depth % 2 == 1)
		tri.order[0] = INC;
//	else
//		tri.order[0] = DEC;
	num = -1;
	while (ft_pow(3, ++num) < tri.num)
	{
		i = -1;
		while (++i < ft_pow(3, num))
		{
			tri.order[ft_pow(3, num)*2 - i -1] = tri.order[i] * -1;
			tri.order[ft_pow(3, num)*3 - i -1] = tri.order[i] * -1;
		}
		i = -1;
		//while (++i < ft_pow(3, num+1))
		//{
		//	ft_printf("%d ", tri.order[i]);
		//}
		//ft_printf("\n");
	}

	
	print_stack(a, b);
	//ft_printf("init_triangle\n");

	if (tri.depth % 2 == 1)
		init_triangle_b(cmd, a, b, &tri);
	else
		init_triangle_a(cmd, a, b, &tri);

	print_stack(a, b);
	//ft_printf("merge\n");
	while (tri.depth--)
	{
		//ft_printf("depth = %d\n", tri.depth);
		if (tri.depth % 2 == 1)
			merge_a2b(cmd, a, b, &tri);
		else
			merge_b2a(cmd, a, b, &tri);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_cmd cmd;

	init(&cmd, &a, &b);
	check_err(argc, argv, &a);
	//ft_printf("inv_cnt = %d\nbefore sort\n", cnt_inverse_order(&a));
	//print_stack(&a, &b);
	sort_stack(&cmd, &a, &b);
	ft_printf("%d number, after sort : inv_cnt = %d\n", a.size, cnt_inverse_order(&a));
	//print_stack(&a, &b);
	
	print_cmd(&cmd);

	// exit_program (free, error handling)
}


