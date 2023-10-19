/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:01:51 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/18 13:54:20 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fill_zeros(int **new, int len, int lcount)
{
	int	i;
	int	j;

	i = 0;
	while (i < lcount + 1)
	{
		j = 0;
		while (j < len + 1)
		{
			new[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	solve(char **table, int len, int lcount)
{
	int		**new;
	int		i;
	int		largest;

	if ((new = (int **)malloc(sizeof(int *) * (lcount + 1))) == NULL)
		return ;
	i = 0;
	while (i < lcount + 1)
	{
		if ((new[i] = (int *)malloc(sizeof(int) * (len + 1))) == NULL)
			return ;
		i++;
	}
	//printf("%d rows\n", lcount);
	fill_zeros(new, len, lcount);
	//printf("\npassed zeros\n");
	largest = calculate_numbers(new, table, len, lcount);
	//printf("\npassed numbers\n");
	find_x(new, len, largest, table, lcount);
	print_table(table, len, lcount);
	//printf("pased print\n");
	i = 0;
	while (i < lcount + 1)
	{
		free(new[i]);
		i++;
	}
	free(new);
}
