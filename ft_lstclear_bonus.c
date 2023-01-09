/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:57:39 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/09 14:57:49 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || *del)
		return ;
	while (*lst)
	{
		temp = *lst;
		ft_lstdelone(*lst, del);
		*lst = temp->next;
	}
}
