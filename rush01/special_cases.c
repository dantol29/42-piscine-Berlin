/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:34:01 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/08 18:34:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_2_3_and_1_2(int **table)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (table[0][i] == 2 && table[5][i] == 3)
			table[2][i] = 4;
		if (table[0][i] == 3 && table[5][i] == 2)
			table[3][i] = 4;
		if (table[i][0] == 3 && table[i][5] == 2)
			table[i][3] = 4;
		if (table[i][0] == 2 && table[i][5] == 3)
			table[i][2] = 4;
		if (table[0][i] == 1 && table[5][i] == 2)
			table[4][i] = 3;
		if (table[0][i] == 2 && table[5][i] == 1)
			table[1][i] = 3;
		if (table[i][0] == 1 && table[i][5] == 2)
			table[i][4] = 3;
		if (table[i][0] == 2 && table[i][5] == 1)
			table[i][1] = 3;
		i++;
	}
}
