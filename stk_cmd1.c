#include "push_swap.h"

void	pa(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;

	if (b->size == 0) 
		return ;
	push(a, pop(b));
	if (ft_strncmp(cmd->last->cmd, "pb", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit(1);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "pa", 4);
//	ft_printf("%s\n", newcmd->cmd);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;	
}

void	pb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;

	if (a->size == 0)
		return ;
	push(b, pop(a));
	if (ft_strncmp(cmd->last->cmd, "pa", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit(1);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "pb", 4);
//	ft_printf("%s\n", newcmd->cmd);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}

void	sa(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;
	
	b->size = b->size;
	if (a->size < 2)
		return ;
	swap(a);
	if (ft_strncmp(cmd->last->cmd, "sa", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	if (ft_strncmp(cmd->last->cmd, "sb", 3) == 0)
	{
		ft_strlcpy(cmd->last->cmd, "ss", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit(1);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "sa", 4);
//	ft_printf("%s\n", newcmd->cmd);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}

void	sb(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*newcmd;
	
	b->size = b->size;
	if (a->size < 2)
		return ;
	swap(b);
	if (ft_strncmp(cmd->last->cmd, "sb", 3) == 0)
	{
		cmd->last = cmd->last->prev;
		free(cmd->last->next);
		cmd->last->next = NULL;
		return ;
	}
	if (ft_strncmp(cmd->last->cmd, "sa", 3) == 0)
	{
		ft_strlcpy(cmd->last->cmd, "ss", 4);
		return ;
	}
	newcmd = (t_node2 *)malloc(sizeof(t_node2));
	if (!newcmd)
		exit(1);
	newcmd->next = 0;
	ft_strlcpy(newcmd->cmd, "sb", 4);
//	ft_printf("%s\n", newcmd->cmd);
	cmd->last->next = newcmd;
	newcmd->prev = cmd->last;
	cmd->last = newcmd;
}

