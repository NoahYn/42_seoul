/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:47 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/28 16:50:02 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free, exit
# include "libft/libft.h"

# define INTMAX 2147483647
# define INTOVER 10000000000
# define INTMIN -2147483648

typedef struct s_node {
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_bst {
	long long		item;
	struct s_bst	*left;
	struct s_bst	*right;
}	t_bst;

typedef struct s_cmd {
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_cmd;


// errorhandle.c
void		init(t_cmd *cmd, t_stack *a, t_stack *b);
long long	ft_atoll(const char *str);
int			isdup(t_bst *curr, int num);
void		check_err(int argc, char *argv[], t_stack *a);
int			cnt_inverse_order(t_stack *stk);

// stack function -> stk_fn.c
void		push(t_stack *stk, int item);
int			pop(t_stack *stk);
void		swap(t_stack *stk);
void		rotate(t_stack *stk);
void		reverse_rotate(t_stack *stk);

// stack command -> stk_cmd[1,2,3].c
void		pa(t_cmd *cmd, t_stack *a, t_stack *b);
void		pb(t_cmd *cmd, t_stack *a, t_stack *b);
void		sa(t_cmd *cmd, t_stack *a, t_stack *b);
void		sb(t_cmd *cmd, t_stack *a, t_stack *b);
void		ss(t_cmd *cmd, t_stack *a, t_stack *b);
void		ra(t_cmd *cmd, t_stack *a, t_stack *b);
void		rb(t_cmd *cmd, t_stack *a, t_stack *b);
void		rr(t_cmd *cmd, t_stack *a, t_stack *b);
void		rra(t_cmd *cmd, t_stack *a, t_stack *b);
void		rrb(t_cmd *cmd, t_stack *a, t_stack *b);
void		rrr(t_cmd *cmd, t_stack *a, t_stack *b);

void		print(t_stack *a, t_stack *b);

#endif


