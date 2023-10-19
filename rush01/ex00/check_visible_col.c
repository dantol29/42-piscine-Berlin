/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visible_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:19:41 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/08 16:02:46 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	check_visible_col(int ***candidates, int **table, int count)
{
	int	j;
	int	max;
	int	visible;
	int	temp;
	int	k;
	int	visible_reverse;
	int	win_cand;
	int	append_cand;

	count -= 1;
	temp = count;
	k = 1;
	while (k < 5)
	{
		count = 10;
		win_cand = 0;
		while (count > 0)
		{
			j = 0;
			visible = 1;
			visible_reverse = 1;
			max = candidates[k - 1][count][j];
			//printf("%d\n", max);
			while (j < 4)
			{
				if(candidates[k - 1][count][j] > max)
				{
					max = candidates[k - 1][count][j];
					visible++;
				}
				j++;
			}
			j = 3;
			max = candidates[k - 1][count][j];
			while (j >= 0)
			{
				if (candidates[k - 1][count][j] > max)
				{
					max = candidates[k - 1][count][j];
					visible_reverse++;
				}
				j--;
			}
			if (visible == table[k][0] && visible_reverse == table[k][5])
			{
				win_cand++;
				//printf("%d win cand\n", win_cand);
				append_cand = count;
				//printf("%d visible, %d visible reverse,  %d row", visible, visible_reverse, k);
				j = 0;
				while (j < 4)
				{
					printf(" %d,", candidates[k - 1][count][j]);
					j++;
				}
				printf("\n");
			}
			count--;
		}
		if (win_cand == 1)
		{
			printf("%d append cand", append_cand);
			j = 1;
			while (j < 5)
			{
				printf("%d new %d row %d col\n\n\n\n\n", candidates[k - 1][append_cand][j - 1], k, j);
				table[k][j] = candidates[k - 1][append_cand][j - 1];
				j++;

			}
		}
		k++;
	}
}

				
