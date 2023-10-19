/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:04:33 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/15 23:31:01 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_number(char *nb)
{
	int	i;

	i = 0;
	if (nb[i] == '-')
		return (0);
	else if (nb[i] == '+')
		i++;
	while (nb[i])
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int argc, char **argv, char **dict_path, char **nb)
{
	if (argc == 2)
	{
		*nb = argv[1];
		if (check_number(*nb) == 1)
			return (1);
		else
			return (0);
	}
	if (argc == 3)
	{
		*dict_path = argv[1];
		*nb = argv[2];
		if (check_number(*nb) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	is_printable(char c)
{
	return (c > 32 && c <= 126);
}
