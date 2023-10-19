/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:09:29 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/18 13:57:41 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void    testprint(int **new);

int	min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	print_table(char **table, int len, int lcount)
{
	int	i;
	int	j;

	i = 0;
	while (i < lcount)
	{
		j = 1;
		while (j < len + 1 && table[i][j])
		{
			write(1, &table[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}

int	formula(int **new, int i, int j, int largest)
{
	new[i + 1][j + 1] = 1 + min(new[i][j], new[i][j + 1], new[i + 1][j]);
	if (new[i + 1][j + 1] > largest)
		largest = new[i + 1][j + 1];
	return (largest);
}

int	calculate_numbers(int **new, char **table, int len, int lcount)
{
	int	i;
	int	j;
	int	largest;

	i = 0;
	largest = 0;
	while (i < lcount)
	{
		j = 0;
		while (j < len + 1)
		{
			if (table[i][j] == 'o')
			{
				if (i == 0)
					new[i + 1][j + 2] = 0;
				else	
					new[i + 1][j + 1] = 0;
			}
			else if (table[i][j] == '.')
			{
				if (i == 0)
					new[i + 1][j + 2] = 1;
				else
					new[i + 1][j + 1] = 1;
			}
			if (new[i + 1][j + 1] == 1)
				largest = formula(new, i, j, largest);
			//ft_putnbr(new[i + 1][j + 1]);
			j++;
		}
		//write(1, "\n", 1);
		i++;
	}
	return (largest);
}
