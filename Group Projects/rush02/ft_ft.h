/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:00:58 by mmejbar           #+#    #+#             */
/*   Updated: 2023/10/15 21:53:33 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FT_H
# define FT_FT_H

# define B_SIZE 4859
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

struct	s_dict
{
	char	**numbers;
	char	**words;
	int		count;
	int		number_len;
};
void	solve(struct s_dict dicitonary, char *str);
void	extract(struct s_dict di, char *str);
char	*print_nb(char *str, struct s_dict di, int to_print, int i);
int		is_power(char *str);
void	find_char(char *str, struct s_dict di);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(long long n);
void	get_dict(char *str, char *dict_path);
int		ft_atoi(char *str);
int		check_arguments(int argc, char **argv, char **dict_path, char **nb);
int		buffer_len(char buffer[B_SIZE]);
void	append_dict(char **numbers, char **words, char *str, int len);
void	print_thousands(struct s_dict di, char *interim, int round);
int		is_printable(char c);
void	free_memory(char **numbers, char **words, int len);
void	call_com(char buffer[B_SIZE], char *str);
void	assign_memory_words(char buffer[B_SIZE], char **words, int len );
void	assign_memory_numbers(char buffer[B_SIZE], char **numbers, int len);
void	fill_array_words(char **words, char buffer[B_SIZE], int len);
void	fill_array_numbers(char **numbers, char buffer[B_SIZE], int len);
void	print_digit(int temp, struct s_dict di);

#endif
