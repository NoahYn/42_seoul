/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:25:42 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/08 15:22:24 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len4(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp2(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{	
	int	s_len;
	int	f_len;

	s_len = ft_len4(str);
	f_len = ft_len4(to_find);
	if (f_len < 1)
		return (str);
	while (*str && s_len + 1 > f_len)
	{
		if (ft_strncmp2(str, to_find, f_len) == 0)
			return (str);
		str++;
		s_len--;
	}
	return (0);
}
