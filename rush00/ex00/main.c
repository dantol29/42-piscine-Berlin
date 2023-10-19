/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:01:13 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/01 14:02:45 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-') 
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0)
			write(1, "numbers should be bigger than 0", 31);
		else
			rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
	else
		write(1, "program takes only 2 arguments", 30);
	return (0);
}
