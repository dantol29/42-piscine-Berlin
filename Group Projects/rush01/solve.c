/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnickl <pnickl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:49 by pnickl            #+#    #+#             */
/*   Updated: 2023/10/08 18:34:57 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_2_3_and_1_2(int **table);

void	check_row_4(int **table)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (table[0][i] == 4)
		{
			table[1][i] = 1;
			table[2][i] = 2;
			table[3][i] = 3;
			table[4][i] = 4;
		}
		if (table[5][i] == 4)
		{
			table[1][i] = 4;
			table[2][i] = 3;
			table[3][i] = 2;
			table[4][i] = 1;
		}
		i++;
	}
}

void	check_col_4(int **table)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (table[i][0] == 4)
		{
			table[i][1] = 1;
			table[i][2] = 2;
			table[i][3] = 3;
			table[i][4] = 4;
		}
		if (table[i][5] == 4)
		{
			table[i][1] = 4;
			table[i][2] = 3;
			table[i][3] = 2;
			table[i][4] = 1;
		}
		i++;
	}
}

void	check_row_1(int **table)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (table[0][i] == 1)
			table[1][i] = 4;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (table[5][i] == 1)
			table[4][i] = 4;
		i++;
	}
}

void	check_col_1(int **table)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (table[i][0] == 1)
			table[i][1] = 4;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (table[i][5] == 1)
			table[i][4] = 4;
		i++;
	}
}

void	solve(int **table)
{
	check_row_4(table);
	check_col_4(table);
	check_row_1(table);
	check_col_1(table);
	check_2_3_and_1_2(table);
}
