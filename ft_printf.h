/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:03:15 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/20 23:48:46 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
void	ft_putstr(char *s, int *num);
void	ft_putnbr(int n, int *num);
void	ft_putui(unsigned int u, int *num);
void	ft_puthex(unsigned int n, char format, int *num);
void	ft_putaddr(unsigned long long n, int *num);

#endif