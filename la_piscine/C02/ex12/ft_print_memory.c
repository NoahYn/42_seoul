/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:18:04 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/12 12:09:04 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hex_addr(unsigned long addr)
{	
	int		i;
	char	caddr[16];

	i = 0;
	while (i < 16)
	{
		if (addr == 0)
			caddr[i] = '0';
		else
			caddr[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i++;
	}
	while (i-- > 0)
		write(1, &caddr[i], 1);
	write(1, ": ", 2);
	return ;
}

void	ft_hex_data(unsigned char *addr, unsigned int size, int lines)
{
	unsigned int	i;

	i = 0;
	if (size >= 16)
		size = 16;
	while (i < 16)
	{
		if (size == 0)
			write(1, "  ", 2);
		else
		{
			size--;
			write(1, &"0123456789abcdef"[addr[i + 16 * lines] / 16], 1);
			write(1, &"0123456789abcdef"[addr[i + 16 * lines] % 16], 1);
		}
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_asc_data(unsigned char *addr, unsigned int size, int lines)
{
	unsigned int	i;

	i = 0;
	if (size >= 16)
		size = 16;
	while (i < size)
	{
		if (addr[i + 16 * lines] < ' ' || addr[i + 16 * lines] > '~')
			write(1, ".", 1);
		else
			write(1, &addr[i + 16 * lines], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_print_lines(unsigned char *addr, unsigned int size, int lines)
{
	ft_hex_addr((unsigned long)(addr + lines * 16));
	ft_hex_data((unsigned char *)addr, size, lines);
	ft_asc_data((unsigned char *)addr, size, lines);
	if (size > 16)
		return (1);
	else
		return (0);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	lines;

	lines = 0;
	while (ft_print_lines(addr, size, lines++))
		size -= 16;
	return (addr);
}

#include <stdio.h>
int main()
{
	char	s12[93] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
	ft_print_memory(s12, 202);
}
