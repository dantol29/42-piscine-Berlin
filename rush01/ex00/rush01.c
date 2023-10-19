/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnickl <pnickl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:17:17 by pnickl            #+#    #+#             */
/*   Updated: 2023/10/08 16:06:28 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	solve(int **table);
void	permutations(int **table);
void	check_numbers(int **table);

int	ft_atoi(char c)
{
	int	i;

	i = c - 48;
	return (i);
}

void	fill_rows(char *argv, int **table)
{
	int	visible;
	int	index;

	visible = 1;
	index = 0;
	while (visible < 5)
	{
		table[0][visible] = ft_atoi(argv[index]);
		visible++;
		index = index + 2;
	}
	visible = 1;
	while (visible < 5)
	{
		table[5][visible] = ft_atoi(argv[index]);
		visible++;
		index = index + 2;
	}	
}	

void	fill_cols(char *argv, int **table)
{
	int	visible;
	int	index;
	
	visible = 1;
	index = 16;
	while (visible < 5)
	{
		table[visible][0] = ft_atoi(argv[index]);
		visible++;
		index = index + 2;
	}
	visible = 1;
	while (visible < 5)
	{
		table[visible][5] = ft_atoi(argv[index]);
		visible++;
		index = index + 2;
	}	
}	
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	char	c;
	c = nb + '0';
	write(1, &c, 1);
}
int	rush01(char *argv)
{
	int	**table;
	int	i;
	int	j;
	int     memory;

        i = 0;  
        table = (int **)malloc(sizeof(int *) * 6);
        while (i < 6)
        {
		table[i] = (int *)malloc(sizeof(int) * 6);
		i++;
        }
	i = 0;
	while (i < 6)
          {
                  j = 0;
                  while (j < 6)
                  {
                          table[i][j] = 0;
                          j++;
                 }
                 i++;
          }
	fill_rows(argv, table);
	fill_cols(argv, table);
	solve(table);
	permutations(table);
	check_numbers(table);
	permutations(table);
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			ft_putnbr(table[i][j]);
			write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
