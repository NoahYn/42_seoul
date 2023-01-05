/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:41:04 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/05 17:41:02 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = (char *)malloc(len1 + len2 + 1);
	if (!strjoin)
		return (0);
	i = -1;
	while (++i < len1)
		strjoin[i] = s1[i];
	i = -1;
	while (++i < len2)
		strjoin[len1 + i] = s2[i];
	strjoin[len1 + len2] = 0;
	return (strjoin);
}
