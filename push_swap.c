/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:30:25 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/23 20:44:21 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_err(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (check_err(argc, argv))
		return (0);
}

// err -> 정수가 아니거나, 정수보다 크거나, 중복 
// atol 로 longlong으로 받은 뒤 정수범위 벗어나는지, 정수 아닌지 확인. 빈도정렬로 중복 확인? 