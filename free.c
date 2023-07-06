/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:11:56 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/06 22:12:09 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	exit_program(t_cmd *cmd, t_stack *a, t_stack *b, t_triangle *tri)
{
	free_cmd(cmd);
	free_stack(a);
	free_stack(b);
	if (tri)
	{
		free(tri->chunk);
		free(tri->order);
	}
	exit(1);
}
