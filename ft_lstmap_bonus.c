/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:58:29 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/16 21:47:26 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	newlst = 0;
	while (lst)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		temp->content = f(lst->content);
		temp->next = 0;
		ft_lstadd_back(&newlst, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (newlst);
}
