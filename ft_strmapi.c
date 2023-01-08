/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:32:03 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 18:49:26 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strmapi;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
		i++;
	strmapi = (char *)malloc(i + 1);
	if (!strmapi)
		return (0);
	strmapi[i] = 0;
	i = 0;
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		++i;
	}
	return (strmapi);
}
