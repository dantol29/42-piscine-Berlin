/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:37:36 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/11 12:57:22 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1)
		return (1);
	else if (*s2)
		return (-1);
	return (0);
}

void	ft_sort_params(char **str, int size)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < (size - 1))
	{
		if (ft_strcmp(str[i], str[i + 1]) == 1)
		{
			temp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = temp;
			i = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		ft_sort_params(argv, argc);
		while (argc > i)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
