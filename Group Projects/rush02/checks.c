/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:38:29 by mmejbar           #+#    #+#             */
/*   Updated: 2023/10/15 20:03:28 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

char	*ft_itoa(long long n)
{
	int		length;
	char	*str;
	int		temp;

	length = 0;
	temp = n;
	while (temp >= 10)
	{
		temp = temp / 10;
		length++;
	}
	str = (char *)malloc(length + 1);
	while (length >= 0)
	{
		str[length] = '0' + (n % 10);
		n /= 10;
		length--;
	}
	return (str);
}

int	is_power(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (0);
	while (str[i])
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	call_com(char buffer[B_SIZE], char *str)
{
	char	**numbers;
	char	**words;

	numbers = (char **)malloc(sizeof(char *) * (buffer_len(buffer)));
	words = (char **)malloc(sizeof(char *) * (buffer_len(buffer)));
	assign_memory_words(buffer, words, buffer_len(buffer));
	assign_memory_numbers(buffer, numbers, buffer_len(buffer));
	fill_array_numbers(numbers, buffer, buffer_len(buffer));
	fill_array_words(words, buffer, buffer_len(buffer));
	append_dict(numbers, words, str, buffer_len(buffer));
	free_memory(numbers, words, buffer_len(buffer));
}
