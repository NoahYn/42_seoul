/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:42 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 08:57:48 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_bst(t_pushswap *ps, t_bst *curr, t_bst *parent, int num)
{
	curr = (t_bst *)malloc(sizeof(t_bst));
	if (!curr)
		exit_program(ps, 0);
	if (num < parent->item)
		parent->left = curr;
	else if (num > parent->item)
		parent->right = curr;
	curr->item = num;
	curr->left = 0;
	curr->right = 0;
}

int	isdup(t_pushswap *ps, t_bst *curr, int num)
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
	init_bst(ps, curr, parent, num);
	return (0);
}

int	cnt_inverse_order(t_stack *stk)
{
	int		cnt;
	t_node	*curr;

	if (stk->size == 0)
		return (0);
	cnt = 0;
	curr = stk->top;
	while (curr->prev)
	{
		if (curr->item > curr->prev->item)
			cnt++;
		curr = curr->prev;
	}
	return (cnt);
}

void	check_err(t_pushswap *ps, char *argv[])
{
	int			i;
	int			j;
	long long	num;

	i = 1;
	ps->bst = (t_bst *)malloc(sizeof(t_bst));
	if (!ps->bst)
		exit_program(ps, 0);
	ps->bst->item = INTOVER;
	ps->bst->left = 0;
	ps->bst->right = 0;
	while (argv[i])
	{
		ps->split = ft_split(argv[i++], ' ');
		j = -1;
		while (ps->split[++j])
		{
			num = ft_atoll(ps->split[j]);
			if (num != (int)num || isdup(ps, ps->bst, num))
				exit_program(ps, "Error\n");
			push(ps, &ps->a, num);
			rotate(&ps->a);
		}
		free_split(ps->split);
	}
}
