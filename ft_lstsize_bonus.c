/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:28:55 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/09 11:29:00 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t size;
	
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
