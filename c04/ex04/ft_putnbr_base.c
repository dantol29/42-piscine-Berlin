/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:52:16 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/19 10:20:45 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_edge_cases(int nbr, char *base)
{
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	else if (nbr < 0)
		write(1, "-", 1);
}

void	ft_calc(int nbr, char *base, int x)
{
	long int	l_nbr;
	int			mod;
	int			temp_arr[100];
	int			i;

	i = 0;
	mod = 0;
	l_nbr = nbr;
	ft_edge_cases(nbr, base);
	if (l_nbr < 0)
		l_nbr *= -1;
	while (l_nbr != 0)
	{
		mod = (l_nbr % x);
		l_nbr = l_nbr / x;
		temp_arr[++i] = mod;
	}
	while (i > 0)
		write(1, &base[temp_arr[i--]], 1);
}

int	ft_base_rules(char *b)
{
	int	i;
	int	j;

	i = 0;
	if (b[0] == '\0' || b[1] == '\0')
		return (0);
	while (b[i] != '\0')
	{
		j = 0;
		if (b[i] < 32 || b[i] == 127 || b[i] == '-' || b[i] == '+')
			return (0);
		while (b[j] != '\0')
		{
			if ((i != j) && (b[i] == b[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_base_rules(base) == 0)
		return ;
	ft_calc(nbr, base, ft_base_rules(base));
	return ;
}
/*
int main (int argc, char *argv[])
{
    int number;
    if (argc != 3)
        return(1);
    number = atoi(argv[1]);
    ft_putnbr_base(number, argv[2]);
    return (0);
}*/
