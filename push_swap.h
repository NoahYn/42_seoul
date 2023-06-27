/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:47 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/27 19:55:22 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // read, write, malloc, free, exit
# include "ft_printf/ft_printf.h"

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

// stack function -> stk_fn.c
void	push(t_stack *stk, int item);
int		pop(t_stack *stk);
void	swap(t_stack *stk);
void	rotate(t_stack *stk);
void	reverse_rotate(t_stack *stk);

#endif
