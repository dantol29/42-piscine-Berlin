/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:44 by zblume            #+#    #+#             */
/*   Updated: 2023/10/18 11:45:17 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putnbr(int nb);
void	place_x(char **table, int largest, int row, int column);
void	print_table(char **table, int len, int lcount);
int		min(int a, int b, int c);
void	solve(char **table, int len, int lcount);
int		ft_maplen(char *str);
int		ft_linecount(char *str);
char	*ft_read_map(char *argv);
char	**map_memory(char *str);
void	fill_map(char *str, char **map);
void	find_x(int **new, int len, int largest, char **table, int lcount);
int		calculate_numbers(int **new, char **table, int len, int lcount);
int		formula(int **new, int i, int j, int largest);
int		ft_row(char **array);

#endif
