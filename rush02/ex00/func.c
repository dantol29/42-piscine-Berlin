/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:48:33 by mmejbar           #+#    #+#             */
/*   Updated: 2023/10/15 21:54:09 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

void	append_dict(char **numbers, char **words, char *str, int len)
{
	struct s_dict	dictionary;

	dictionary.numbers = numbers;
	dictionary.count = len;
	dictionary.words = words;
	dictionary.number_len = ft_strlen(str);
	solve(dictionary, str);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	buffer_len(char buffer[1024])
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (buffer[i] && buffer[i + 1])
	{
		if (buffer[i] == '\n' && is_printable(buffer[i + 1]))
			len++;
		i++;
	}
	return (len + 1);
}

void	solve(struct s_dict di, char *str)
{
	int		i;
	int		to_print;
	int		round;

	i = 0;
	round = (di.number_len - 1) / 3;
	if (round * 3 >= ft_strlen(di.numbers[di.count - 1]))
		write(1, "Dict Error", 10);
	else if (di.number_len == 1 && str[i] == '0')
		find_char ("0", di);
	else
	{
		while (str[i])
		{
			to_print = (di.number_len - i) % 3;
			if (to_print == 0)
				to_print = 3;
			print_thousands(di, print_nb(str, di, to_print, i), round);
			i += to_print;
			round--;
		}
	}
}

void	free_memory(char **numbers, char **words, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(numbers[i]);
		free(words[i]);
		i++;
	}
}
