/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:04 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/08 16:15:32 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	check_numbers(int **table)
{
	int	rows;
	int	i;
	int	number;
	int	count;
	int	empty_row;
	int	state;
	int	six;

	number = 1;
	while (number < 5)
	{
		rows = 1;
		count = 0;
		six = 6;
		empty_row = 0;
		while (rows < 5)
		{
			i = 1;
			state = 0;
			while (i < 5)
			{
				if (table[rows][i] == number)
				{
					count++;
					state = 1;
					six = six + 1 - i;
					//printf("%d six\n", six);
				}
				if (i + 1 == 5)
				{
					if (state == 0)
					{
					//	printf("%d empty row for %d number\n", rows, number);
						empty_row = rows;
					}
				}
				i++;
			}
			//printf("%d count for %d number\n", count, number);
			if (count == 3 && rows == 4)
                	{
                        	//printf("%d number enters if on %d row and %d col\n", number, empty_row, six + 1);
                        	table[empty_row][six + 1] = number;
                	}

			rows++;
		}
		number++;
	}
	//printf("the end of 1\n\n\n");
}
