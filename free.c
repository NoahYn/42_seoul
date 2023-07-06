/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:11:56 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 00:48:27 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (split)
	{
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
	}
}

void	free_stack(t_stack *stk)
{
	while (stk->size)
	{
		pop(stk);
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_node2	*prev;
	t_node2	*curr;

	curr = cmd->first;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}

void	free_bst(t_bst *root)
{
	if (root == 0)
		return ;
	if (root->left)
		free_bst(root->left);
	if (root->right)
		free_bst(root->right);
	free(root);
}

void	exit_program(t_pushswap *ps, char *str)
{
	free_cmd(&ps->cmd);
	free_stack(&ps->a);
	free_stack(&ps->b);
	if (ps->tri.chunk)
	{
		free(ps->tri.chunk);
		free(ps->tri.order);
	}
	free_bst(ps->bst);
	if (str)
		ft_printf("%s", str);
	exit(1);
}
