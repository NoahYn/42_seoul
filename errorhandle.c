#include "push_swap.h"

void	init(t_cmd *cmd, t_stack *a, t_stack *b)
{
	t_node2	*dummy;

	a->size = 0;
	a->top = NULL;
	a->bottom = NULL;
	b->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	dummy = (t_node2 *)malloc(sizeof(t_node2));
	dummy->next = NULL;
	dummy->prev = NULL;
	ft_strlcpy(dummy->cmd, "", 1);
	cmd->first = dummy;
	cmd->last = dummy;
}

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

int cnt_inverse_order(t_stack *stk)
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

void	check_err(int argc, char *argv[], t_stack *a)
{
	int			i;
	char		**split;
	long long	num;
	t_bst		root;

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
			rotate(a);
		}
	}
	if (argc < 2 || !cnt_inverse_order(a))
		exit(1);
}