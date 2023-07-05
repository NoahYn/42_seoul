/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:47 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/05 13:16:53 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free, exit
# include "libft/libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648
# define INTOVER 10000000000

# define INC 1
# define DEC -1

# define AT	a->top->item
# define AS	a->top->prev->item
# define AB	a->bottom->item
# define AB2 a->bottom->next->item

# define BT b->top->item
# define BS b->top->prev->item
# define BB b->bottom->item
# define BB2 b->bottom->next->item

typedef struct s_node {
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
// node for stack
typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;
typedef struct s_node2 {
	char cmd[4];
	struct s_node2 *prev;
	struct s_node2 *next;
}	t_node2;
// node for cmd set
typedef struct s_cmd {
	t_node2 *first;
	t_node2 *last;
}	t_cmd;

typedef struct s_triangle {
	int		*chunk;
	int		*order;
	int		num;
	int		depth;
	int		push_cnt;
}	t_triangle;



typedef struct s_bst {
	long long		item;
	struct s_bst	*left;
	struct s_bst	*right;
}	t_bst;



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

// debug.c
void		print_stack(t_stack *a, t_stack *b);
void		print_cmd(t_cmd *cmd);

// cmd_utils.c
void		do_cmds(char *cmdset, t_cmd *cmd, t_stack *a, t_stack *b);
void		cmd_multiply(char *cmdset, int num, t_cmd *cmd, t_stack *a, t_stack *b);

// sort_small.c
void		sort_small_a(t_cmd *cmd, t_stack *a, t_stack *b);
void		find_min(int min_idx[2], t_stack *stk);
void		sort_three_a(t_cmd *cmd, t_stack *a, t_stack *b);
void		pb_min(t_cmd *cmd, t_stack *a, t_stack *b, int num);


#endif


