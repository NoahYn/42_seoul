/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:17:08 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/10 12:17:41 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_check(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (i);
		i++;
	}
	return (-42);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	index = find_check(str, to_find);
	if (to_find[0] == '\0')
		return (str);
	if (index == -42)
		return (0);
	return (&str[index]);
}
