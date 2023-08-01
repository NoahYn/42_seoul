/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:32:26 by geonwule          #+#    #+#             */
/*   Updated: 2022/09/11 23:04:17 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_atoa(char *str);
char	*ft_strdup(char *src, int start, int end);
int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
int		ft_space(char c);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char *str, char *charset);
int		ft_printable(char c);
int		ft_num(char c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_sort_string(char **tab);
int		ft_print_all(char *num, char *dic);
void	ft_print_one(char num, int zeros, int unit, char *dic);
void	ft_print_two(char *n, int unit, char *dic);

#endif
