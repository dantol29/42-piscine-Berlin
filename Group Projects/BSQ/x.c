/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:11:49 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/18 12:34:35 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	place_x(char **table, int largest, int row, int column)
{
	int	k;
	int	j;

	k = 0;
	while (k < largest)
	{
		if (row - k >= 0 && column - k >= 0)
		{
			j = 0;
			while (j < largest)
			{
				table[row - k][column - j] = 'x';
				j++;
			}
		}
		k++;
	}
}

void	find_x(int **new, int len, int largest, char **table, int lcount)
{
	int	i;
	int	j;

	i = 1;
	while (i < lcount + 1)
	{
		j = 1;
		while (j < len + 2)
		{
			if (new[i][j] == 0)
				table[i - 1][j - 1] = 'o';
			else if (new[i][j] >= 1)
				table[i - 1][j - 1] = '.';
			if (new[i][j] == largest)
			{
				place_x(table, largest, i - 1, j - 1);
				largest = -1;
			}
			j++;
		}
		i++;
	}
}
