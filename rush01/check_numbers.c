/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:04 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/08 17:40:53 by pnickl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	unique_num(int **table, int number, int rows, int empty_row)
{
	int	count;
	int	i;
	int	six;
	int	state;

	state = 0;
	count = 0;
	i = 1;
	six = 6;
	while (i < 5)
	{
		if (table[rows][i] == number)
		{
			count++;
			state = 1;
			six = six + 1 - i;
		}
		if (i + 1 == 5)
			if (state == 0)
				empty_row = rows;
		i++;
	}
	if (count == 3 && rows == 4)
		table[empty_row][six + 1] = number;
}

void	check_numbers(int **table)
{
	int	rows;
	int	number;
	int	empty_row;

	empty_row = 0;
	number = 1;
	while (number < 5)
	{
		rows = 1;
		while (rows < 5)
		{
			unique_num(table, number, rows, empty_row);
			rows++;
		}
		number++;
	}
}
