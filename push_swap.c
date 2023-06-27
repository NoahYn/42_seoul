/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/27 20:30:45 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (*str < '0' || *str > '9')
		return (INTOVER);
	while (*str >= '0' && *str <= '9')
		result = 10 * result + sign * (*str++ - '0');
	return (result);
}

int	isdup(t_bst *curr, int num)
{
	t_bst	*parent;

	if (curr->item == INTOVER)
	{
		curr->item = num;
		return (0);
	}
	while (curr)
	{
		parent = curr;
		if (num < curr->item)
			curr = curr->left;
		else if (num > curr->item)
			curr = curr->right;
		else
			return (1);
	}
	curr = (t_bst *)malloc(sizeof(t_bst));
	if (num < parent->item)
		parent->left = curr;
	else if (num > parent->item)
		parent->right = curr;
	curr->item = num;
	return (0);
}

void	check_err(int argc, char *argv[], t_stack *a)
{
	int			i;
	char		**split;
	long long	num;
	t_bst		root;

	if (argc < 2)
		exit(1);
	i = 1;
	root.item = INTOVER;
	root.left = 0;
	root.right = 0;
	while (argv[i])
	{
		split = ft_split(argv[i++], ' ');
		while (*split)
		{
			num = ft_atoll(*(split++));
			if (num != (int)num || isdup(&root, num))
			{
				ft_printf("Error\n");
				exit(1);
			}
			push(a, num);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
//	t_stack	b;

	check_err(argc, argv, &a);
}
