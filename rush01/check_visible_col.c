/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visible_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:19:41 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/08 18:22:30 by vhodis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	vis_reverse(int ***candidates, int count, int k)
{
	int	j;
	int	max;
	int	visible_reverse;

	j = 3;
	visible_reverse = 1;
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
	return (visible_reverse);
}

int	vis(int ***candidates, int count, int k)
{
	int	j;
	int	visible;
	int	max;

	j = 0;
	visible = 1;
	max = candidates[k - 1][count][j];
	while (j < 4)
	{
		if (candidates[k - 1][count][j] > max)
		{
			max = candidates[k - 1][count][j];
			visible++;
		}
		j++;
	}
	return (visible);
}

void	write_cand(int ***candidates, int append_cand, int k, int **table)
{
	int	j;

	j = 1;
	while (j < 5)
	{
		if (append_cand != 0)
			append_cand -= 1;
		table[j][k] = candidates[k - 1][append_cand][j - 1];
		j++;
	}
}

void	check_visible_col(int ***candidates, int **table, int count, int k)
{
	int	visible;
	int	visible_reverse;
	int	win_cand;
	int	append_cand;

	count = 23;
	win_cand = 0;
	while (count >= 0)
	{
		visible = vis(candidates, count, k);
		visible_reverse = vis_reverse(candidates, count, k);
		if (visible == table[k][0] && visible_reverse == table[k][5])
		{
			win_cand++;
			append_cand = count;
		}
		count--;
	}
	if (win_cand == 1)
		write_cand(candidates, append_cand, k, table);
}

void	main_check(int ***candidates, int **table, int count)
{
	int	k;

	k = 1;
	while (k < 5)
	{
		check_visible_col(candidates, table, count, k);
		k++;
	}
}
