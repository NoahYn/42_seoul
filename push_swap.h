/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:47 by sunyoon           #+#    #+#             */
/*   Updated: 2023/07/07 00:34:33 by sunyoon          ###   ########.fr       */
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

# define AT	ps->a.top->item
# define AS	ps->a.top->prev->item
# define AB	ps->a.bottom->item
# define AB2 ps->a.bottom->next->item

# define BT ps->b.top->item
# define BS ps->b.top->prev->item
# define BB ps->b.bottom->item
# define BB2 ps->b.bottom->next->item

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
	char			cmd[4];
	struct s_node2	*prev;
	struct s_node2	*next;
}	t_node2;
// node for cmd set
typedef struct s_cmd {
	t_node2	*first;
	t_node2	*last;
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

typedef struct s_pushswap {
	t_stack		a;
	t_stack		b;
	t_cmd		cmd;
	t_triangle	tri;
	t_bst		*bst;
	char		**split;
}	t_pushswap;

void		init(t_pushswap *ps);
long long	ft_atoll(const char *str);
// errorhandle.c
void		check_err(t_pushswap *ps, char *argv[]);
int			cnt_inverse_order(t_stack *stk);
int			isdup(t_bst *curr, int num);

// stack function -> stk_fn.c
void		push(t_stack *stk, int item);
int			pop(t_stack *stk);
void		swap(t_stack *stk);
void		rotate(t_stack *stk);
void		reverse_rotate(t_stack *stk);

// stack command -> stk_cmd[1,2].c
void		pa(t_pushswap *ps);
void		pb(t_pushswap *ps);
void		sa(t_pushswap *ps);
void		sb(t_pushswap *ps);
void		ra(t_pushswap *ps);
void		rb(t_pushswap *ps);
void		rra(t_pushswap *ps);
void		rrb(t_pushswap *ps);

// debug.c
void		print_stack(t_stack *a, t_stack *b);
void		print_cmd(t_cmd *cmd);

// cmd_utils.c
void		do_cmds(t_pushswap *ps, char *cmdset, int num);

// sort_small.c
void		sort_small_a(t_pushswap *ps);
void		find_min(int min_idx[2], t_stack *stk);
void		sort_three_a(t_pushswap *ps);
void		pb_min(t_pushswap *ps, int num);

// merge.c
void		merge_aab(t_pushswap *ps, int seq);
void		merge_bba(t_pushswap *ps, int seq);
void		merge_a2b(t_pushswap *ps);
void		merge_b2a(t_pushswap *ps);

// merge_utils.c
int			max_element(int num, int *arr, int *size);
int			min_element(int num, int *arr, int *size);
void		init_triunit_a(t_pushswap *ps);
void		init_triunit_b(t_pushswap *ps);

// free.c
void		free_split(char **split);
void		free_stack(t_stack *stk);
void		free_cmd(t_cmd *cmd);
void		free_bst(t_bst *bst);
void		exit_program(t_pushswap *ps, char *str);

#endif
