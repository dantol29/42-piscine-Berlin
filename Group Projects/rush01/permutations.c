/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnickl <pnickl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:22:35 by pnickl            #+#    #+#             */
/*   Updated: 2023/10/08 23:37:47 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
void	ft_putnbr(int nb);
void	main_check(int ***candidates, int **table, int count);


void	check_visible(int ***candidates, int **table, int count)
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
		count = temp;
		win_cand = 0;
		while (count >= 0)
		{
			j = 0;
			visible = 1;
			visible_reverse = 1;
			max = candidates[k - 1][count][j];
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
				append_cand = count;
				j = 0;
				while (j < 4)
				{
					j++;
				}
			}
			count--;
		}
		if (win_cand == 1)
		{
			j = 1;
			while (j < 5)
			{
				table[k][j] = candidates[k - 1][append_cand][j - 1];
				j++;

			}
		}
		k++;
	}
}

void	print_permutations(int ***candidates)
{
	int	j;
	int	i;
	int	k;

	k = 1;
	while (k < 5)
	{
		i = 0;
		j = 0;
		while (candidates[k-1][i])
        	{
                		j = 0;
               			while (j < 4)
                		{
                        		j++;
                		}
                		i++;
        	}
		k++;
	}
}

void	permutations_col(int permutations[24][4], int **table)
{
	int	i;
	int	k;
	int	bla;
	int	count;
	int	state;
	int	j;
	int	***candidates_col;
	int	win_col;
	int	append_count;

	candidates_col = (int ***)malloc(sizeof(int **) * 4);
	i = 0;
	while (i < 4)
	{
		candidates_col[i] = (int **)malloc(sizeof(int *) * 24);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 24)
		{
			candidates_col[i][j] = (int *)malloc(sizeof(int) * 4);
			j++;
		}
		i++;
	}
	
	k = 1;
	while (k < 5)
	{
	i = 0;
	win_col = 0;
	count = 0;
	append_count = 0;
	while (i < 24)
	{
		j = 1;
		state = 1;
		bla = 0;
		while (j < 5 && state == 1)
		{	
			if (table[j][k] != 0)
			{
				if (table[j][k] != permutations[i][bla])
					{
						state = 0;
					}

			}
			bla++;
			j++;
		}
		if (state == 1)
		{
			win_col++;
			append_count = count;
			bla = 0;
			while (bla < 4)
			{
				candidates_col[k - 1][count][bla] = permutations[i][bla];
				bla++;	
			}
			count++;
		}
		i++;
	}
	if (win_col == 1)
	{
		j = 1;
		while(j < 5)
		{
			table[j][k] = candidates_col[k - 1][append_count][j - 1];
			j++;
		}
	}
	k++;
	}
	main_check(candidates_col, table, count);
	print_permutations(candidates_col);


}

void	permutations(int **table)
{
	int	i;
	int	j;
	int	***candidates;
	int	count;
	int	state;
	int	bla;
	int	k;

	candidates = (int ***)malloc(sizeof(int **) * 4);
	i = 0;
	while (i < 4)
	{
		candidates[i] = (int **)malloc(sizeof(int *) * 24);
		i++;
	}
	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 24)
		{
			candidates[i][j] = (int *)malloc(sizeof(int) * 4);
			j++;
		}
		i++;
	}

	int	permutations[24][4] = {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, {1, 3, 4, 2},
	{1, 4, 2, 3}, {1, 4, 3, 2}, {2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4},
        {2, 3, 4, 1}, {2, 4, 1, 3}, {2, 4, 3, 1}, {3, 1, 2, 4}, {3, 1, 4, 2},
        {3, 2, 1, 4}, {3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1}, {4, 1, 2, 3},
        {4, 1, 3, 2}, {4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1}};	
	count = 0;
	k = 1;
	while (k < 5)
	{
	i = 0;
	while (i < 24)
	{
		j = 1;
		state = 1;
		bla = 0;
		while (j < 5 && state == 1)
		{	
			if (table[k][j] != 0)
			{
				if (table[k][j] != permutations[i][bla])
						state = 0;
			}
			bla++;
			j++;
		}
		if (state == 1)
		{
			bla = 0;
			while (bla < 4)
			{
				if (count == 24)
					count--;
				candidates[k - 1][count][bla] = permutations[i][bla];
				bla++;	
			}

			count++;
		}
		i++;
	}
	k++;
	}
	check_visible(candidates, table, count);
	permutations_col(permutations, table);
}
