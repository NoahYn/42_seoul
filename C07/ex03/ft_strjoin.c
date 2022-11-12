/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:16:46 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/14 22:37:33 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen3(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *srcs)
{
	int	i;
	int	d_len;

	i = 0;
	d_len = ft_strlen3(dest);
	while (srcs[i])
	{
		dest[d_len + i] = srcs[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*join;

	if (size == 0)
	{
		join = (char *)malloc(sizeof(char));
		join[0] = '\0';
		return (join);
	}
	i = size;
	len = ft_strlen3(sep) * (size - 1);
	while (i > 0)
		len += ft_strlen3(strs[--i]);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (join == 0)
		return (0);
	join[0] = '\0';
	ft_strcat(join, strs[i++]);
	while (i < size)
	{
		ft_strcat(join, sep);
		ft_strcat(join, strs[i++]);
	}
	return (join);
}
