/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:33:01 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/16 21:37:57 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (i < len && s[i + start])
		++i;
	len = i;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[i])
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}
