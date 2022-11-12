/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:44:08 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/13 12:26:54 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	free_mall(char **dic_2, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(dic_2[i]);
		i++;
	}
	free(dic_2);
}

char	*ft_sort_array(char *buff)
{
	char	**dic_2;
	char	*new_dic;
	int		d_len;

	dic_2 = ft_split(buff, "\n");
	ft_sort_string(dic_2);
	d_len = 0;
	while (dic_2[d_len] != 0)
		d_len++;
	new_dic = ft_strjoin(d_len, dic_2, "\n");
	free_mall(dic_2, d_len);
	return (new_dic);
}

void	ft_sep(char *key, char *dict)
{
	int		fd;
	char	buff[20000];
	char	*dic;

	fd = open(dict, O_RDONLY);
	dic = ft_sort_array(buff);
	if (fd == -1 || ((read(fd, buff, 20000 - 1)) == -1)
		|| !dic)
	{
		write(2, "Dict Error\n", 11);
		return ;
	}
	if (!ft_print_all(key, dic))
	{
		write(2, "Dict Error\n", 11);
		return ;
	}
	free(dic);
	free(key);
	close (fd);
}

int	main(int ac, char **av)
{
	char *temp;

	if (!(ac >= 2 && ac <= 3))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	else
	{
		if (ac == 2)
		{
			temp = ft_atoa(av[1]);
			if (temp == 0)
				return (-1);
			ft_sep(temp, "numbers.dict");
		}
		else if (ac == 3)
		{
			temp = ft_atoa(av[2]);
			if (temp == 0)
				return (-1);
			ft_sep(temp, av[1]);
		}
		else
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	system("leaks rush-02");
	return (0);
}
