/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:25:45 by mmejbar           #+#    #+#             */
/*   Updated: 2023/10/15 23:31:31 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

char	*print_nb(char *str, struct s_dict di, int to_print, int i)
{
	int		j;
	char	*inter;

	j = 0;
	inter = (char *)malloc(sizeof(char) * 4);
	while (j < to_print)
	{
		inter[j] = str[i];
		i++;
		j++;
	}
	inter[j] = '\0';
	extract(di, inter);
	return (inter);
}

void	print_thousands(struct s_dict di, char *inter, int round)
{
	char	*sep;
	int		k;

	if (ft_strcmp(inter, "000") != 0)
	{
		sep = (char *)malloc(sizeof(char) * (round * 3 + 1));
		k = 0;
		if (round >= 0)
		{
			sep[k] = '1';
			while (k < round * 3)
			{
				k++;
				sep[k] = '0';
			}
			sep[k + 1] = '\0';
			if (ft_strcmp(sep, "1"))
				find_char(sep, di);
			free(sep);
		}
	}
}

void	find_char(char *str, struct s_dict di)
{
	int	i;

	i = 0;
	while (i <= di.count)
	{
		if ((ft_strcmp(str, di.numbers[i]) == 0))
		{
			ft_putstr(di.words[i]);
			break ;
		}
		i++;
	}
	write(1, " ", 1);
}

void	print_digit(int temp, struct s_dict di)
{
	int		result;
	char	*digit;

	result = (temp / 10) * 10;
	if (result != 0)
		find_char(ft_itoa(result), di);
	digit = (char *)malloc(2);
	digit[0] = (temp % 10) + '0';
	digit[1] = '\0';
	if (ft_strcmp(digit, "0") != 0)
		find_char(digit, di);
	free(digit);
}

void	extract(struct s_dict di, char *str)
{
	int		temp;

	temp = ft_atoi(str) / 100;
	if (temp != 0)
	{
		find_char(ft_itoa(temp), di);
		find_char("100", di);
	}
	temp = ft_atoi(str) % 100;
	if (temp <= 20 || temp % 10 == 0)
	{
		if (temp != 0)
			find_char(ft_itoa(temp), di);
	}
	else
		print_digit(temp, di);
}
