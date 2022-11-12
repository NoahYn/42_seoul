/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:42:12 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/03 19:39:57 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

void	ft_quick_sort(int *tab, int start, int end)
{
	int	p;
	int	s;
	int	e;
	int	pivot;

	if (end <= start)
		return ;
	p = (start + end) / 2;
	s = start;
	e = end;
	pivot = tab[p];
	while (s < e)
	{
		while (tab[s] < pivot)
			s++;
		while (tab[e] > pivot)
			e--;
		if (s < e)
			ft_swap(&tab[s], &tab[e]);
	}
	ft_quick_sort(tab, start, s);
	ft_quick_sort(tab, s + 1, end);
	return ;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		start;
	int		end;

	start = 0;
	end = size - 1;
	ft_quick_sort (tab, start, end);
}
/*
int main()
{
	int	i = 0;
	char ctab[10];
	int tab[10] = {1, 4, 5, 7, 3, 2, 6, 0, 9, 8};
	ft_sort_int_tab(tab, 10);
	while (i < 10)
	{
		ctab[i] = tab[i] + '0';
		write(1, &ctab[i], 1);
		i++;
	}
	return 0;
}
*/
