/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:47 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/29 21:28:38 by sunyoon          ###   ########.fr       */
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

# define B1 a->top->item
# define B2 a->bottom->item
# define B3 b->bottom->item

# define A1 b->top->item
# define A2 b->bottom->item
# define A3 a->bottom->item

# define T1 a->top->item
# define T2 a->top->prev->item
# define T3 a->top->prev->prev->item

// do cmd -> 문자열, 스플릿, 하나씩 실행 ex "sa ra pb" -> 세개 실행

typedef struct s_node {
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_node2 {
	char cmd[4];
	struct s_node2 *prev;
	struct s_node2 *next;
}	t_node2;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// order 1 is increasing, 0 is decreasing
typedef struct s_triangle {
	int	vertex[3];
	int vtx_size[3];
	int order;
}	t_triangle;

typedef struct s_bst {
	long long		item;
	struct s_bst	*left;
	struct s_bst	*right;
}	t_bst;

typedef struct s_cmd {
	t_node2 *first;
	t_node2 *last;
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


